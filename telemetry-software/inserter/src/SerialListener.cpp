
#include "SerialListener.hpp"
#include <cstring>

#include <iostream>
#include <errno.h>
#include <cassert>  
#include <limits.h>

void PrintErrno()
{
  std::cout << "ERROR: " << errno << " : " << strerror(errno) << std::endl;
}

//
// Serial Listener public interface
//

SerialListener::SerialListener(const std::string& device_name)
  : device_name(device_name)
{
  // Open the serial port
  if (!OpenSerial())
    throw SerialException("Failed to open serial port");

  // Configure the serial port
  int error = ConfigureSerial();
  if (error)
  {
    std::cout << "An error occured when configuring serial port" << std::endl;
    PrintErrno();
    // It has been observed that some error on tcsetattr do not affect usability
    // of the serial port (WSL), so we continue regardless
    std::cout << "Continuing execution, stability cannot be ensured" << std::endl;
  }

  // Make sure state of serial is ready-to-use, otherwise cannot continue execution
  assert(serial_port > 0);
  if (serial_port < 0)
    throw SerialException(std::string("Failed to open serial port, port was < 0"));
}

SerialListener::~SerialListener()
{
  CloseSerial();
}

bool SerialListener::Read(std::array<uint8_t, SERIAL_READ_SIZE>& buffer,
			  size_t& size_read)
{
  // Buffer is size guaranteed and below the max allowed size
  static_assert(SERIAL_READ_SIZE <= SSIZE_MAX);

  // Receive in buffer of SERIAL_READ_SIZE bytes
  int readn = read(serial_port, buffer.data(), SERIAL_READ_SIZE);
  if (readn < 0)
  {
    std::cout << "\nError on serial port read : " << std::endl;
    PrintErrno();
    size_read = 0;
    return false;
  }

  size_read = static_cast<size_t>(readn);
  bytes_read += size_read;
  return true;
}


//
// Serial Listener private functions
//

bool SerialListener::OpenSerial()
{
  // Open the serial port
  // Using O_NONBLOCK returns the error 11 with EAGAIN, which indicates
  // that the call to read() would have blocked
    std::cout << "Open serial port : " << device_name << std::endl;
  serial_port = open(device_name.c_str(), F_SETFL, O_RDONLY | O_NONBLOCK);
  if (serial_port < 0)
  {
    std::cout << "Failed to open serial port : " << device_name << std::endl;
    PrintErrno();
    return false;
  }
    std::cout << "Opened serial port" << std::endl;
    
    fcntl(serial_port, F_SETFL, O_RDONLY & ~O_NONBLOCK);

  return true;
}

void SerialListener::CloseSerial()
{
  close(serial_port);
}

int SerialListener::ConfigureSerial()
{
  assert(serial_port > 0);
  if (serial_port < 0)
    throw SerialException("Failed to configure TTY, serial port was < 0");

  // Error code to return when done
  int error_code = 0;
  
  if (tcgetattr(serial_port, &tty))
  {
    std::cout << "tcgetattr encountered an error : " << std::endl;
    error_code = errno;
  }
  
  // Parity
  tty.c_cflag &= ~PARENB; // Disable parity
  // Stop bit
  tty.c_cflag &= ~CSTOPB; // 1 stop bit
  // RTS/CTS
  tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS

  // bit size
  tty.c_cflag &= ~CSIZE;
  tty.c_cflag |= CS8; // 8 bits per word

  tty.c_cflag |= CREAD | CLOCAL;

  // Canonical mode (line by line reading)
  tty.c_lflag &= ~ICANON; // Disabling canonical

  // Disable extended input processing
  tty.c_lflag &= ~IEXTEN;

  // Disable echoing of characters
  tty.c_lflag &= ~(ECHO | ECHOE | ECHONL);
  
  // Disable INTR, QUIT and SUSP characters (signal chars are not processed)
  tty.c_lflag &= ~ISIG;

  // Disable software flow control
  tty.c_iflag &= ~(IXON | IXOFF | IXANY);
  // Disable parity error checking (no parity)
  tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | IGNCR | INPCK);
  // Disable re-mapping of CR/LF characters to New Line
  tty.c_iflag &= ~(INLCR | ICRNL);

  tty.c_oflag &= ~OPOST;
  tty.c_oflag &= ~ONLCR;

  // Single char received is enough to return from read() call
  // Disable inter-character timer
  tty.c_cc[VTIME] = 1; // Time in deciseconds (=1s)
  tty.c_cc[VMIN] = 1;

  // Baud rate
  // if (cfsetispeed(&tty, B19200) < 0)
  if (cfsetispeed(&tty, B115200) < 0)
  {
    std::cout << "cfsetispeed() set input speed to 19200 baudrate failed with error : " << errno << std::endl;
    error_code = errno;
  }    
  // if (cfsetospeed(&tty, B19200) < 0)
  if ( cfsetospeed(&tty, B115200) < 0)
  {
    std::cout << "cfsetospeed() set output speed to 19200 baudrate failed with error : " << errno << std::endl;
    error_code = errno;
  }

  if (tcsetattr(serial_port, TCSANOW, &tty))
  {
    std::cout << "tcsetattr encountered an error : " << std::endl;
    error_code = errno;
  }

  return error_code;
}
