#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "socket_common.h"

const char LOACLHOST[] = "127.0.0.1"; // local connection

class Client
{
public:
  Client(uint16_t server_port);
  ~Client();
  int Init();
  int Main();
  void Stop();

private:
  int client_socket_;
  uint16_t server_port_;
  bool isRunning_;
};

#endif
