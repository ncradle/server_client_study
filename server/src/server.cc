#include "server.h"

int main()
{
  const uint16_t SERVER_PORT = 12345;
  const int MAX_CLIENT = 5;
  int err = 0;

  // 1:socket
  // A socket is created with socket
  // AF_INET     : ipv4
  // SOCK_STREAM : tcp
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0)
  {
    perror("socket");
    return -1;
  }

  int yes = 1;
  err = setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
  if (err < 0)
  {
    perror("socket option");
    return -1;
  }

  // 2:bind
  // The socket is bound to a local address using bind
  // so that other sockets may be "connect"ed to it.
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;
  err = bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (err < 0)
  {
    std::cout << errno << std::endl;
    perror("bind");
    return -1;
  }

  // 3:listen
  // A willingness to accept incoming connections and
  // a queue limit for incoming connections are specified with listen
  err = listen(server_socket, MAX_CLIENT);
  if (err < 0)
  {
    perror("listen");
    return -1;
  }

  // 4:accept
  struct sockaddr_in client_addr;
  socklen_t len = sizeof(client_addr);
  int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &len);
  if (client_socket < 0)
  {
    perror("accept");
    return -1;
  }

  // write
  int write_num = 0;
  write_num = write(client_socket, "Hello", sizeof("Hello"));
  if (write_num < 0)
  {
    perror("write");
    return -1;
  }

  // close client connection
  err = close(client_socket);
  if (err < 0)
  {
    perror("close client");
    return -1;
  }

  // close listen
  err = close(server_socket);
  if (err < 0)
  {
    perror("close server");
    return -1;
  }

  return 0;
}
