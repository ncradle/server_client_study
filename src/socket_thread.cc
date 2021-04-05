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

  std::this_thread::sleep_for(std::chrono::microseconds(1000));

  server.Stop();
  client.Stop();
  th0.join();
  th1.join();
}
