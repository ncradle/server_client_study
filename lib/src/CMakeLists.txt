cmake_minimum_required(VERSION 3.2)
add_library(tcp_lib STATIC client.cc server.cc)
target_include_directories(tcp_lib PRIVATE ../include)
