#include "client.h"

Client::Client(uint16_t server_port) : client_socket_{INVALID_SOCKET}, server_port_{server_port}, isRunning_{false} {}

Client::~Client()
{
  if (client_socket_)
  {
    close(client_socket_);
  }
}

int Client::Init()
{
  // 1:socket
  // A socket is created with socket
  // socket_family = AF_INET          : ipv4
  // socket_type   = SOCK_STREAM      : tcp
  // protocol      = 0 / IPPROTO_TCP? : it is default
  // ToDo : serching IPPROTO_TCP
  client_socket_ = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket_ < 0)
  {
    perror("socket");
    return -1;
  }
  return 0;
}

int Client::Recv()
{
  // 2:connect
  // connect server socket
  // sin_family      = AF_INET              : ipv4
  // sin_addr.s_addr = inet_addr(LOACLHOST) : ip address
  // sin_port        = htons(SERVER_PORT)   : port
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(LOACLHOST);
  server_addr.sin_port = htons(server_port_);
  int err = 0;
  err = connect(client_socket_, reinterpret_cast<struct sockaddr *>(&server_addr), sizeof(server_addr));
  if (err < 0)
  {
    perror("connect");
    return -1;
  }
  isRunning_ = true;

  while (isRunning_)
  {
    // read
    char buf[10] = {};
    int read_num = 0;
    read_num = read(client_socket_, buf, 10);
    if (read_num == 0)
    {
      std::cout << "connection end" << std::endl;
      break;
    }
    if (read_num < 0)
    {
      perror("read");
    }
    std::cout << buf << std::endl;
  }

  err = close(client_socket_);
  client_socket_ = INVALID_SOCKET;
  if (err < 0)
  {
    perror("close client");
    return -1;
  }
  return 0;
}

void Client::Send(const char *msg, const size_t size)
{
  size_t offset = 0;
  while (offset < size)
  {
    ssize_t write_num = send(client_socket_, msg + offset, size - offset, SEND_FLAG);
    if (write_num < 0)
    {
      perror("write");
      break;
    }
    offset += static_cast<size_t>(write_num);
  }
}

void Client::Stop()
{
  isRunning_ = false;
}
