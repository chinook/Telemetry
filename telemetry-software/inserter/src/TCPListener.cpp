
#include "TCPListener.hpp"

#include <iostream>

TCPListener::TCPListener(std::string ip_address, uint32_t port)
  : ip_address(ip_address), port(port)
{
}

TCPListener::~TCPListener()
{
}


bool TCPListener::OpenTCPSocket()
{
  asio::error_code asio_ec;

  asio::io_context context;

  // Create an asio endpoint to target
  asio::ip::tcp::endpoint endpoint(asio::ip::make_address(ip_address, asio_ec), port);

  // Create a socket for connection
  socket = asio::ip::tcp::socket(context);
  if (!socket.has_value())
    return false;

  // Try to connect to socket
  socket.value().connect(endpoint, asio_ec);
  if (!asio_ec)
  {
    std::cout << "Successfully connected to socket " << ip_address << ":" << port << std::endl;
    return true;
  }
  else
  {
    std::cout << "Failed to connect to socket " << ip_address << ":" << port << std::endl;
    return false;
  }
}
