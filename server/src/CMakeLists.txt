cmake_minimum_required(VERSION 3.2)
add_library(tcp_server STATIC server.cc)
target_include_directories(tcp_server PRIVATE ../include)
