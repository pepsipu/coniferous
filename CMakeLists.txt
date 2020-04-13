cmake_minimum_required(VERSION 3.15)
project(coniferious)
set(CMAKE_CXX_STANDARD 14)

add_executable(coniferious src/main.cpp src/UI.cpp src/UI.h)
include_directories("vendor")
target_link_libraries(coniferious SDL2)
target_link_libraries(coniferious SDL2_ttf)