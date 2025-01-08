
#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include <map>

#include <string.h>
#include <chrono>
#include <thread>
using namespace std::chrono_literals;

#include "CanDecoder.hpp"
#include "SerialListener.hpp"
#include "InfluxInserter.hpp"
#include "TCPListener.hpp"

// Default values for serial reading and database writing
std::string db_name = "chinook_db1";
std::string hostname = "influxdb";
std::string tty_name = "tty.usbserial-DN05ZN9L";

// Batch size to send to InfluxDB
const uint32_t DEFAULT_BATCH_SIZE = 50;

// Function to parse command line arguments
// -emulate         : Sets inserter to run as standalone without serial port, all values
//                    are randomly generated into database
// -tty <tty>       : Sets the TTY serial input to read from. Takes in name only (without /dev/)
// -dbname <name>   : Sets name of db to use in InfluxDB
// -hostname <name> : Sets name of host hosting the influxdb/grafana servers. Docker uses alias 'influxdb'
//                    whereas running standalone will typically be 'localhost'
// Returns map of all boolean arguments passed in
std::map<std::string_view, bool> ParseCommandLineArgs(int argc, char* argv[])
{
  // Result map
  std::map<std::string_view, bool> result;

  auto SetString = [&argc, &argv](int& i, std::string& dest)
  {
    if (i+1 < argc)
    {
      dest = std::string(argv[i+1]);
      ++i;
    }
  };
  
  for (int i = 1; i < argc; ++i)
  {
    char* arg = argv[i];
    if (!strcmp(arg, "-emulate"))
      {
	// Set emulate option to true
	result["emulate"] = 1;
      }
    else if (!strcmp(arg, "-tty"))
      {
	// Select tty to use
	SetString(i, tty_name);
      }
    else if (!strcmp(arg, "-dbname"))
      {
	// db name to use
	SetString(i, db_name);
      }
    else if (!strcmp(arg, "-hostname"))
      {
	// hostname to use
	SetString(i, hostname);
      }
    else
      {
	// Un-recognized command line argument
	// Not critical, simply advice user
	std::cout << "Warning : Unrecognized command line arg : " << arg << std::endl;
      }
  }

  return result;
}

int main(int argc, char* argv[])
{
  std::cout << "\nTelemetry backend v1.0 \n\n" << std::endl;
 
  std::map<std::string_view, bool> args = ParseCommandLineArgs(argc, argv);
  
  bool emulate_serial = args.find("emulate") != args.end();

  // Init TCP listener
  // TCPListener tcp = TCPListener("174.142.90.39", 9202);
  // bool tcp_success = tcp.OpenTCPSocket();
  // if (!tcp_success)
  // return 1;
  
  // Read data from the TCP server (iweb)
  // std::cout << "Connected. Trying to read data from server" << std::endl;
  
  /*std::optional<asio::ip::tcp::socket>& socket = tcp.GetSocket();
  if (!socket.has_value())
  {
    std::cout << "TCP socket error, failed to create socket" << std::endl;
    return 1;
  }
  */
  /*
  while (1)
  {
    asio::streambuf response;

    asio::error_code ec;
    size_t n_bytes = asio::read(socket.value(), response, asio::transfer_exactly(15), ec);
    std::cout << "bytes = " << n_bytes << std::endl;

    if (ec)
    {
      std::cout << "Error reading" << std::endl;
      return 1;
    }
    else
    {
      std::istream stream(&response);
      //std::cout << std::hex << stream.rdbuf() << std::endl;
      std::streambuf* buffer = stream.rdbuf();
      size_t buffer_size = buffer->in_avail();
      for (int i = 0; i < n_bytes; ++i)
      {
	std::cout << std::hex << buffer->snextc();
      }
      std::cout << std::dec << std::endl;
    }
  }
  */

  // Init serial
  std::string tty_serial_port = "/dev/" + tty_name;
  std::shared_ptr<SerialListener> serial = nullptr;
  if (!emulate_serial)
    serial = std::make_shared<SerialListener>(tty_serial_port);
  
  // Init can decoder
  std::shared_ptr<CanDecoder> decoder = nullptr;
  if (!emulate_serial)
    decoder = std::make_shared<RawDataCanDecoder>();
  else
    decoder = std::make_shared<EmulateCanDecoder>();
  
  // Init InfluxDB inserter
  InfluxInserter influx(hostname, db_name, DEFAULT_BATCH_SIZE);
  
  while (true)
  {
    //std::this_thread::sleep_for(1s);
    std::array<uint8_t, SERIAL_READ_SIZE> raw_serial;
    memset(raw_serial.data(), 0, sizeof(raw_serial));
    size_t size_read = 0;
    
    // Reading the serial
    if (!emulate_serial)
    {
      bool read_success = serial->Read(raw_serial, size_read);
      if (!read_success)
        continue;
      if (size_read == 0)
          continue;
    }
    
    // Process raw can frames
    std::vector<DecodedCanValue> decoded_values =
      decoder->Process(raw_serial, size_read);
    
    // Write points into InfluxDB
    influx.WriteValues(decoded_values);

    // Print debug/logging information
    static auto last_time = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::now();
    std::chrono::duration<double> delta = time - last_time;
    if (delta.count() >= 1)
    {
      // Serial info
      if (!emulate_serial)
      {
	std::cout << "Bytes read = " << serial->GetBytesRead() << std::endl;
	serial->ResetBytesRead();
      }
      
      // Decoder info
      decoder->PrintCounters();
      decoder->ResetCounters();
      
      last_time = time;
    }
  }
}
