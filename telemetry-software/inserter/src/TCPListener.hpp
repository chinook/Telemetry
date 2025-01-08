
#ifndef TCP_LISTENER_HPP
#define TCP_LISTENER_HPP

#include <string>
#include <vector>
#include <array>

#include <unistd.h>
#include <stdio.h>
#include <exception>
#include <optional>

#define ASIO_STANDALONE
#include "asio.hpp"
#include "asio/ts/buffer.hpp"
#include "asio/ts/internet.hpp"

class TCPListener
{
public:
  // Constructor of TCP Listener object
  TCPListener(std::string ip_address, uint32_t port);
  ~TCPListener();

  // Open TCP socket
  bool OpenTCPSocket();

  std::optional<asio::ip::tcp::socket>& GetSocket() { return socket; }

private:

  std::optional<asio::ip::tcp::socket> socket;

  // TCP socket info
  std::string ip_address = "127.0.0.1";
  uint32_t port = 80;
};

#endif // TCP_LISTENER_HPP
