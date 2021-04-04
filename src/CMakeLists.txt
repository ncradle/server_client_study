cmake_minimum_required(VERSION 3.2)

add_executable(socket_thread socket_thread.cc)
target_include_directories(socket_thread PRIVATE ../include)
target_include_directories(socket_thread PRIVATE ../server/include)
target_include_directories(socket_thread PRIVATE ../client/include)

# It is required to use c++11 <thread> library find_package -> search
# FindThreads and create target Threads::Threads. ToDo setting cmake-format to
# wrap back
find_package(Threads REQUIRED)
target_link_libraries(socket_thread PRIVATE Threads::Threads)
target_link_libraries(socket_thread PRIVATE tcp_server)
target_link_libraries(socket_thread PRIVATE tcp_client)
