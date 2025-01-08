
#ifndef CAN_DECODER_HPP
#define CAN_DECODER_HPP

#include <string.h>
#include <limits>
#include <unordered_map>
#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <algorithm>
#include <string_view>
#include <memory>
#include <variant>

#include "SerialListener.hpp"

// Definitions of the CAN BUS used for decoding
#include "telemetry_memstruct.h"

// Message constexpr map
//
// The messages are provided through the telemetry_memstruct.h file
// Messages are written an in array format :
// 
// CAN_MESSAGES = {
//   MESSAGE_ID
//   {
//     signals ...
//   }
//   ...
// }
//
// Every message is provided sequentially in the array
// Every message contains an array of signal declarations
//
// For convenience, the ConstexprMap acts like a HashMap
// by parsing the array to find a given key (iterates over the messages)
//
template <typename Key, typename Value, std::size_t size>
struct ConstexprMap
{
    std::array<std::pair<Key, Value>, size> data;
    
    constexpr Value at(const Key& key) const
    {
        const auto itr = std::find_if(begin(data), end(data),
                                      [&key](const auto& v){ return v.first == key; });
        if (itr != end(data))
            return itr->second;
        else
            throw std::range_error("Key Not Found");
    }
};

// Map for accessing message declarations from ID (aka map)
// Created at compile time
static constexpr auto CAN_DECODE = ConstexprMap<uint32_t, MessageDecode, CAN_MESSAGES.size()>{{ CAN_MESSAGES }};


//
// CRC calculations helper functions
//

namespace CRC
{

// CRC-8, poly = x^8 + x^2 + x^1 + x^0, init = 0
static char CRC8_TABLE[] = {
    	(char) 0x00, (char) 0x5e, (char) 0xbc, (char) 0xe2, (char) 0x61, (char) 0x3f, (char) 0xdd, (char) 0x83,
    	(char) 0xc2, (char) 0x9c, (char) 0x7e, (char) 0x20, (char) 0xa3, (char) 0xfd, (char) 0x1f, (char) 0x41,
    	(char) 0x9d, (char) 0xc3, (char) 0x21, (char) 0x7f, (char) 0xfc, (char) 0xa2, (char) 0x40, (char) 0x1e,
    	(char) 0x5f, (char) 0x01, (char) 0xe3, (char) 0xbd, (char) 0x3e, (char) 0x60, (char) 0x82, (char) 0xdc,
    	(char) 0x23, (char) 0x7d, (char) 0x9f, (char) 0xc1, (char) 0x42, (char) 0x1c, (char) 0xfe, (char) 0xa0,
    	(char) 0xe1, (char) 0xbf, (char) 0x5d, (char) 0x03, (char) 0x80, (char) 0xde, (char) 0x3c, (char) 0x62,
    	(char) 0xbe, (char) 0xe0, (char) 0x02, (char) 0x5c, (char) 0xdf, (char) 0x81, (char) 0x63, (char) 0x3d,
    	(char) 0x7c, (char) 0x22, (char) 0xc0, (char) 0x9e, (char) 0x1d, (char) 0x43, (char) 0xa1, (char) 0xff,
    	(char) 0x46, (char) 0x18, (char) 0xfa, (char) 0xa4, (char) 0x27, (char) 0x79, (char) 0x9b, (char) 0xc5,
    	(char) 0x84, (char) 0xda, (char) 0x38, (char) 0x66, (char) 0xe5, (char) 0xbb, (char) 0x59, (char) 0x07,
    	(char) 0xdb, (char) 0x85, (char) 0x67, (char) 0x39, (char) 0xba, (char) 0xe4, (char) 0x06, (char) 0x58,
    	(char) 0x19, (char) 0x47, (char) 0xa5, (char) 0xfb, (char) 0x78, (char) 0x26, (char) 0xc4, (char) 0x9a,
    	(char) 0x65, (char) 0x3b, (char) 0xd9, (char) 0x87, (char) 0x04, (char) 0x5a, (char) 0xb8, (char) 0xe6,
    	(char) 0xa7, (char) 0xf9, (char) 0x1b, (char) 0x45, (char) 0xc6, (char) 0x98, (char) 0x7a, (char) 0x24,
    	(char) 0xf8, (char) 0xa6, (char) 0x44, (char) 0x1a, (char) 0x99, (char) 0xc7, (char) 0x25, (char) 0x7b,
    	(char) 0x3a, (char) 0x64, (char) 0x86, (char) 0xd8, (char) 0x5b, (char) 0x05, (char) 0xe7, (char) 0xb9,
    	(char) 0x8c, (char) 0xd2, (char) 0x30, (char) 0x6e, (char) 0xed, (char) 0xb3, (char) 0x51, (char) 0x0f,
    	(char) 0x4e, (char) 0x10, (char) 0xf2, (char) 0xac, (char) 0x2f, (char) 0x71, (char) 0x93, (char) 0xcd,
    	(char) 0x11, (char) 0x4f, (char) 0xad, (char) 0xf3, (char) 0x70, (char) 0x2e, (char) 0xcc, (char) 0x92,
    	(char) 0xd3, (char) 0x8d, (char) 0x6f, (char) 0x31, (char) 0xb2, (char) 0xec, (char) 0x0e, (char) 0x50,
    	(char) 0xaf, (char) 0xf1, (char) 0x13, (char) 0x4d, (char) 0xce, (char) 0x90, (char) 0x72, (char) 0x2c,
    	(char) 0x6d, (char) 0x33, (char) 0xd1, (char) 0x8f, (char) 0x0c, (char) 0x52, (char) 0xb0, (char) 0xee,
    	(char) 0x32, (char) 0x6c, (char) 0x8e, (char) 0xd0, (char) 0x53, (char) 0x0d, (char) 0xef, (char) 0xb1,
    	(char) 0xf0, (char) 0xae, (char) 0x4c, (char) 0x12, (char) 0x91, (char) 0xcf, (char) 0x2d, (char) 0x73,
    	(char) 0xca, (char) 0x94, (char) 0x76, (char) 0x28, (char) 0xab, (char) 0xf5, (char) 0x17, (char) 0x49,
    	(char) 0x08, (char) 0x56, (char) 0xb4, (char) 0xea, (char) 0x69, (char) 0x37, (char) 0xd5, (char) 0x8b,
    	(char) 0x57, (char) 0x09, (char) 0xeb, (char) 0xb5, (char) 0x36, (char) 0x68, (char) 0x8a, (char) 0xd4,
    	(char) 0x95, (char) 0xcb, (char) 0x29, (char) 0x77, (char) 0xf4, (char) 0xaa, (char) 0x48, (char) 0x16,
    	(char) 0xe9, (char) 0xb7, (char) 0x55, (char) 0x0b, (char) 0x88, (char) 0xd6, (char) 0x34, (char) 0x6a,
    	(char) 0x2b, (char) 0x75, (char) 0x97, (char) 0xc9, (char) 0x4a, (char) 0x14, (char) 0xf6, (char) 0xa8,
    	(char) 0x74, (char) 0x2a, (char) 0xc8, (char) 0x96, (char) 0x15, (char) 0x4b, (char) 0xa9, (char) 0xf7,
    	(char) 0xb6, (char) 0xe8, (char) 0x0a, (char) 0x54, (char) 0xd7, (char) 0x89, (char) 0x6b, (char) 0x35};

  
// Get CRC value for a given message
static uint8_t GetCRC(const std::vector<uint8_t>& message)
{
  // CRC8_TABLE should always be of size 256
  static_assert((std::numeric_limits<uint8_t>::max() + 1) == sizeof(CRC8_TABLE));
  
  uint8_t crc = 0;
  for (int i = 0; i < message.size(); ++i)
  {
    uint8_t index = crc ^ message[i];
    crc = CRC8_TABLE[index];
  }
  return crc;
}
  
}


//
// Helper functions for swapping endianness
//

#define SWAP32(x) (((x) & 0xff) << 24 | ((x) & 0xff00) << 8 | ((x) & 0xff0000) >> 8 | ((x) >> 24) & 0xff)
#define SWAP16(x) (((x) & 0xff00) >> 8 | ((x) & 0x00ff) << 8)


//
// Helper structs for decoding CAN information
//

// Represents the raw data of a CAN frame
// Raw data of Process needs to be in this format
struct CanFrame
{
  // Union let's us get the message without CRC by calling .message directly
  union
  {
    struct
    {
      std::array<uint8_t, 2> header;
      std::array<uint8_t, 4> id;
      std::array<uint8_t, 8> data;
    };
    std::array<uint8_t, 14> message;
  };
  uint8_t crc;
};

// Output of decoded can frames
struct DecodedCanValue
{
  // Mapping of string (name) to float (value)
  std::pair<std::string, std::variant<int, long long int, std::string, double>> key_value_pair;
};


//
// Abstract class of all CAN decoders
// Cannot be instantiated
//
class CanDecoder
{
public:

  // This function is pure-virtual, meaning it cannot be instantiated (class cannot
  // be constructed) but is an interface for other children classes to override
  //
  // Reads the serial port and processes the read message in a format
  // ready for output
  // [OUT] decoded_values    : Output values as key-value pairs (name -> value)
  // [OUT]                   : Returns True on success, False otherwise
  virtual std::vector<DecodedCanValue> Process(const std::array<uint8_t, SERIAL_READ_SIZE>& raw_data, size_t size) = 0;
  
  void ResetCounters()
  {
    for (auto it = CAN_MESSAGES.begin(); it != CAN_MESSAGES.end(); ++it)
    {
      // NOTE: The map [] operator also adds the key if it's not already present
      msg_count[it->second.id] = 0;
    }
    amt_msg_bytes = 0;
    amt_total_msgs = 0;
    amt_msg_wrong_length = 0;
    amt_msg_wrong_crc = 0;
    amt_msg_unknown_id = 0;
  }
  
  void PrintCounters()
  {
    std::cout << "msg bytes = " << amt_msg_bytes << "  :  # msgs = " << amt_total_msgs << std::endl;
    if (amt_msg_wrong_length || amt_msg_wrong_crc || amt_msg_unknown_id)
    {
      std::cout << "Warning: wrong length = " << amt_msg_wrong_length << " : wrong CRC = " << amt_msg_wrong_crc << " : unknown id = " << amt_msg_unknown_id << std::endl;
    }
  }

protected:
  virtual ~CanDecoder() {}
  
  // Counting number of messages by id
  std::unordered_map<uint32_t, uint32_t> msg_count;
  
  // Processed message byte + amount counters
  uint32_t amt_msg_bytes = 0;
  uint32_t amt_total_msgs = 0;
  
  // Error counters
  uint32_t amt_msg_wrong_length = 0;
  uint32_t amt_msg_wrong_crc = 0;
  uint32_t amt_msg_unknown_id = 0;
  
private:
  
};


//
// CanDecoder class to decode messages from the serial port
//

class RawDataCanDecoder : public CanDecoder
{
public:
  
  RawDataCanDecoder();
  ~RawDataCanDecoder();
  
  // Processes the message raw data in a format
  // ready for output
  // [IN]  raw_data          : Raw data from input
  // [IN]  size              : Size of data passed in raw_data
  // [OUT] decoded_values    : Returns output values as key-value pairs (name->value)
  std::vector<DecodedCanValue> Process(const std::array<uint8_t, SERIAL_READ_SIZE>& raw_data, size_t size) override;
  
private:
  // Private functions for decoding serial inputs
  
  // Returns id as an int from 4 bytes, does not affect endianness
  // [IN] data               : The 4 bytes representing the id in the frame
  // [OUT] uint32_t          : ID as uint32_t
  uint32_t ConvertID(const std::array<uint8_t, 4>& data);
  
  // Process a signal from a can frame
  // [IN] sig_dec            : SignalDecode struct to use for decoding
  // [IN] data               : Array of 8 bytes of data to process
  // [OUT] signal_values     : Output values as key-value pairs (name -> value)
  void ProcessSignal(const SignalDecode& sig_dec,
		     const std::array<uint8_t, 8>& data,
		     std::vector<DecodedCanValue>& signal_values);
  
  // Process a CAN frame of 15 bytes
  // Writes logging information on incoming data
  // [IN] frame              : CanFrame to process
  // [OUT] signal_values     : Signal values decoded in key-value pairs
  void ProcessMessage(const CanFrame& frame,
		      std::vector<DecodedCanValue>& signal_values);
    
  // Global buffer for storing raw CAN data
  std::vector<uint8_t> buffer;
  int index = 0;
  
  // Logging message count per id
  std::unordered_map<uint32_t, uint32_t> msg_count;
  
  uint32_t msg_bytes = 0;
  uint32_t total_msgs = 0;
  
  // Serial interface reference
  std::unique_ptr<SerialListener> serial;
};


//
// CanDecoder class for emulating random data
//

class EmulateCanDecoder : public CanDecoder
{
public:

  EmulateCanDecoder();
  ~EmulateCanDecoder();

  // Emulates serial data and outputs data in a key-value pair format
  // [IN] raw_data           : Raw data from input (can be empty)
  // [IN] size               : Size of raw data passed in (can be zero)
  // [OUT] decoded_values    : Returns output values as key-value pairs (name->value)
  std::vector<DecodedCanValue> Process(const std::array<uint8_t, SERIAL_READ_SIZE>& raw_data, size_t size) override;
  
private:
  
};

#endif // CAN_DECODER_HPP
