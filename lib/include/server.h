#ifndef SERVER_H_
#define SERVER_H_

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

const int MAX_CLIENT = 5; // client queue for

class Server
{
public:
  Server(uint16_t server_port);
  ~Server();
  int Init();
  int Main();
  void Stop();

private:
  int server_socket_;
  uint16_t server_port_;
  int client_socket_;
  bool isRunning_;
};

#endif
