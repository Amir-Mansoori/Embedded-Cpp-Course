cmake_minimum_required(VERSION 3.10)
project(MyEmbeddedApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

include_directories(src)
add_executable(app src/main.cpp src/utils.cpp)
