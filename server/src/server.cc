#include "server.h"

Server::Server() : server_socket_{0}, client_socket_{0}, isRunning_{true} {}

Server::~Server() {}

int Server::Init()
{ // 1:socket
  // A socket is created with socket
  // socket_family = AF_INET          : ipv4
  // socket_type   = SOCK_STREAM      : tcp
  // protocol      = 0 / IPPROTO_TCP? : it is default
  // ToDo : serching IPPROTO_TCP
  server_socket_ = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket_ < 0)
  {
    perror("socket");
    return -1;
  }

  int err;
  // this option command
  // enable to re-bind same port before release from WAIT_TIME
  // "yes" must be int type
  const int yes = 1;
  err = setsockopt(server_socket_, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
  if (err < 0)
  {
    perror("socket option");
    return -1;
  }

  // 2:bind
  // The socket is bound to a local address using bind
  // so that other sockets may be "connect"ed to it.
  // sin_family      = AF_INET              : ipv4
  // sin_addr.s_addr = inet_addr(LOACLHOST) : ip address
  // sin_port        = htons(SERVER_PORT)   : port
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;
  err = bind(server_socket_, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (err < 0)
  {
    std::cout << errno << std::endl;
    perror("bind");
    return -1;
  }

  // 3:listen
  // A willingness to accept incoming connections and
  // a queue limit for incoming connections are specified with listen
  err = listen(server_socket_, MAX_CLIENT);
  if (err < 0)
  {
    perror("listen");
    return -1;
  }

  return 0;
}

int Server::Main()
{ // 4:accept
  struct sockaddr_in client_addr;
  socklen_t len = sizeof(client_addr);
  client_socket_ = accept(server_socket_, (struct sockaddr *)&client_addr, &len);
  if (client_socket_ < 0)
  {
    perror("accept");
    return -1;
  }

  while (isRunning_)
  {
    // write
    int write_num = 0;
    write_num = write(client_socket_, "123456", 6);
    if (write_num < 0)
    {
      perror("write");
      return -1;
    }
  }

  int err;
  // close client connection
  err = close(client_socket_);
  if (err < 0)
  {
    perror("close client");
    return -1;
  }

  // close listen
  err = close(server_socket_);
  if (err < 0)
  {
    perror("close server");
    return -1;
  }

  return 0;
}

void Server::Stop()
{
  isRunning_ = false;
}
