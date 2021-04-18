#include "socket_thread.h"
#include "client.h"
#include "server.h"

int main()
{
  const uint16_t SERVER_PORT = 12345;
  Server server(SERVER_PORT);
  Client client(SERVER_PORT);
  server.Init();
  client.Init();
  std::thread th0([&server] { server.Recv(); });
  std::thread th1([&client] { client.Recv(); });
  std::this_thread::sleep_for(std::chrono::microseconds(1000));
  server.Send("1", 1);
  std::this_thread::sleep_for(std::chrono::microseconds(1000));
  client.Send("2", 1);
  std::this_thread::sleep_for(std::chrono::microseconds(1000));
  server.Send("123", 3);
  std::this_thread::sleep_for(std::chrono::microseconds(1000));
  client.Send("123", 3);

  server.Stop();
  client.Stop();
  th0.join();
  th1.join();
}
