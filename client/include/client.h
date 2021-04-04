#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

const uint16_t SERVER_PORT = 12345;   // connect port
const char LOACLHOST[] = "127.0.0.1"; // local connection

class Client
{
public:
  Client();
  ~Client();
  int Init();
  int Main();

private:
  int client_socket;
};

#endif
