cmake_minimum_required(VERSION 3.27)
project(bouncy_balls)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/modules)
set(SDL2_PATH "../../../frameworks/SDL2-2.30.0\\x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(bouncy_balls ../src/main.cpp)

target_link_libraries(bouncy_balls ${SDL2_LIBRARY})