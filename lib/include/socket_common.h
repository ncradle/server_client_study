#ifndef SOCKET_COMMON_H_
#define SOCKET_COMMON_H_

const int INVALID_SOCKET = -1;
constexpr int SEND_FLAG = MSG_DONTWAIT | MSG_NOSIGNAL;
const int MAX_RECV_BUF_SIZE = 1024;

#endif
