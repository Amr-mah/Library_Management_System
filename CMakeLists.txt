cmake_minimum_required(VERSION 3.20)
project(Library_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Library_Management_System main.cpp Library.cpp Library.h Book.cpp Book.h)
