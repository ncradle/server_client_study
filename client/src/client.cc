#include "client.h"

int main()
{
  const uint16_t SERVER_PORT = 12345;
  // 1:socket
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);

  // 2:connect
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_addr.sin_port = htons(SERVER_PORT);
  connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

  // read
  char buf[10] = {};
  read(client_socket, buf, 10);
  std::cout << buf << std::endl;

  close(client_socket);
  return 0;
}
