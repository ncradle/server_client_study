#include "socket_thread.h"

void greet_fun()
{
  while (1)
  {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "hello" << std::endl;
  }
}

void byte_fun()
{
  while (1)
  {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "bye" << std::endl;
  }
}

int main()
{
  std::thread th0(greet_fun);
  std::thread th1(byte_fun);

  th0.detach();
  th1.detach();
  unsigned int i, j;
  for (i = 0; i < 0xffffffff; i++)
  {
  }
}
