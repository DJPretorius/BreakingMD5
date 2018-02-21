cmake_minimum_required(VERSION 3.9)
project(BreakingMD5)

set(CMAKE_CXX_STANDARD 11)

#include_directories(C:/Universiteit/GIT/C++Libraries/openssl)

add_executable(BreakingMD5 main.cpp md5.h md5.cpp Reduction.cpp Reduction.h)