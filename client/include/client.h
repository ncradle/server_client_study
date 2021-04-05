#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

const uint16_t CONNECT_PORT = 12345;  // server port
const char LOACLHOST[] = "127.0.0.1"; // local connection

class Client
{
public:
  Client();
  ~Client();
  int Init();
  int Main();
  void Stop();

private:
  int client_socket_;
  bool isRunning_;
};

#endif
