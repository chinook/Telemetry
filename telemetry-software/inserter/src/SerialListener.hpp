
#ifndef SERIAL_LISTENER_HPP
#define SERIAL_LISTENER_HPP

#include <string>
#include <vector>
#include <array>

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <memory>

#include <exception>

// Number of bytes to read from serial at a time
#define SERIAL_READ_SIZE 64


class SerialListener
{
public:
  
  // Constructor of Serial listener object
  // Throw a SerialException if serial port couldn't be opened
  // [IN]  tty_name    : name of TTY serial port, in format '/dev/ttyXYZ'
  SerialListener(const std::string& device_name);
  ~SerialListener();

  // Call this method periodically to read data from serial port
  // Blocks on call if no data available
  // [IN]  buffer      : pointer to uint8_t array of size SERIAL_READ_SIZE
  // [OUT] size_read   : number of bytes read into buffer
  // [OUT] bool        : True on successful read, False otherwise
  bool Read(std::array<uint8_t, SERIAL_READ_SIZE>& buffer, size_t& size_read);

  void ResetBytesRead() { bytes_read = 0; }
  uint32_t GetBytesRead() { return bytes_read; }
  
private:
  
  // Open serial port
  // Throws an exception if serial port is invalid for an unknown reason
  // [OUT] bool        : True on successful open, False otherwise
  bool OpenSerial();

  // Close serial port
  void CloseSerial();
  
  // Setting attributes of the serial port
  // Because it has been shown that some errors do not reflect serial usability,
  // this function does not exit on error,
  // but simply returns the error to the caller
  // [OUT] int         : errno returned by either tcgetattr or tcsetattr
  int ConfigureSerial();

  // Reference to the serial port
  std::string device_name = "/dev/ttyUSB0";
  int serial_port = -1;

  // Serial port configuration settings
  termios tty;

  // Amount of bytes read
  uint32_t bytes_read = 0;
};


//
// SerialException class
// Used for specific exceptions on the serial port
//

class SerialException : public std::runtime_error
{
public:
  SerialException(const std::string& msg) : std::runtime_error(msg) {}
};


#endif // SERIAL_LISTENER_HPP
