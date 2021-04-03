cmake_minimum_required(VERSION 3.2)

add_executable(socket_thread.out socket_thread.cc)
target_include_directories(socket_thread.out PRIVATE ../include)

# It is required to use c++11 <thread> library find_package -> search
# FindThreads and create target Threads::Threads. ToDo setting cmake-format to
# wrap back
find_package(Threads REQUIRED)
target_link_libraries(socket_thread.out PRIVATE Threads::Threads)
