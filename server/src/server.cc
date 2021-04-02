#include "server.h"

int main()
{
  const uint16_t SERVER_PORT = 12345;
  const int MAX_CLIENT = 5;

  // 1:socket
  // A socket is created with socket
  // AF_INET     : ipv4
  // SOCK_STREAM : tcp
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  int yes = 1;
  err = setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
  // 2:bind
  // The socket is bound to a local address using bind
  // so that other sockets may be "connect"ed to it.
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;
  bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

  // 3:listen
  // A willingness to accept incoming connections and
  // a queue limit for incoming connections are specified with listen
  listen(server_socket, MAX_CLIENT);

  // 4:accept
  struct sockaddr_in client_addr;
  socklen_t len = sizeof(client_addr);
  int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &len);

  // write
  write(client_socket, "Hello", 5);

  // close client connection
  close(client_socket);

  // close listen
  close(server_socket);

  return 0;
}
