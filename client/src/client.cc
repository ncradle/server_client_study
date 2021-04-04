#include "client.h"

Client::Client() : client_socket{0} {}

Client::~Client() {}

int Client::Init()
{
  // 1:socket
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket < 0)
  {
    perror("socket");
    return -1;
  }
  return 0;
}

int Client::Main()
{
  // 2:connect
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(LOACLHOST);
  server_addr.sin_port = htons(SERVER_PORT);
  int err = 0;
  err = connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (err < 0)
  {
    perror("connect");
    return -1;
  }
  // read
  char buf[10] = {};
  int read_num = 0;
  read_num = read(client_socket, buf, 10);
  if (read_num < 0)
  {
    perror("read");
  }
  std::cout << buf << std::endl;

  err = close(client_socket);
  if (err < 0)
  {
    perror("close client");
    return -1;
  }
  return 0;
}
