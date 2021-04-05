#include "socket_thread.h"
#include "client.h"
#include "server.h"

int main()
{
  Server server;
  Client client;
  server.Init();
  client.Init();
  std::thread th0([&server] { server.Main(); });
  std::thread th1([&client] { client.Main(); });

  th0.detach();
  th1.detach();
  unsigned int i, j;
  for (i = 0; i < 0xffffffff; i++)
  {
  }
}
