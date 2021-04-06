cmake_minimum_required(VERSION 3.2)
add_library(tcp_client STATIC client.cc)
target_include_directories(tcp_client PRIVATE ../include)
