cmake_minimum_required(VERSION 3.15)
project(coniferious)
set(CMAKE_CXX_STANDARD 14)

add_executable(coniferious src/main.cpp src/Display.cpp src/Display.h)
target_link_libraries(coniferious SDL2)