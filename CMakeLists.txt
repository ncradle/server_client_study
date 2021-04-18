cmake_minimum_required(VERSION 3.2)

# set the project name
project(socket VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(lib)
add_subdirectory(src)
