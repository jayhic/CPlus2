cmake_minimum_required(VERSION 3.6)
project(Project_II)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp std_lib_facilities.h Game.cpp Game.h)
add_executable(Project_II ${SOURCE_FILES})