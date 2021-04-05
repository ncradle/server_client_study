#ifndef SERVER_H_
#define SERVER_H_

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

const uint16_t SERVER_PORT = 12345; // server port num
const int MAX_CLIENT = 5;           // client queue for

class Server
{
public:
  Server();
  ~Server();
  int Init();
  int Main();
  void Stop();

private:
  int server_socket;
  int client_socket;
  bool isRunning;
};

#endif
