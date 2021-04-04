#include "socket_thread.h"
#include "client.h"
#include "server.h"

int main()
{
  Server server;
  Client client;
  server.Init();
  client.Init();
  std::thread th0(&Client::Main, &client);
  std::thread th1(&Server::Main, &server);

  th0.detach();
  th1.detach();
  unsigned int i, j;
  for (i = 0; i < 0xffffffff; i++)
  {
  }
}
