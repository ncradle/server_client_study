#include "client.h"

int main()
{
  // 1:socket
  int client_server = socket(AF_INET, SOCK_STREAM, 0);

  // 2:connect
  struct sockaddr_in client_addr;
  client_addr.sin_family = AF_INET;
  client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  client_addr.sin_port = htons(8000);
  connect(client_server, (struct sockaddr *)&client_addr, sizeof(client_addr));

  close(client_server);
  return 0;
}
