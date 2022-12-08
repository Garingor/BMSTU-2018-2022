cmake_minimum_required(VERSION 3.15)
project(lab_03 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab_03 main.c const.h input.c input.h memory.c memory.h menu.c menu.h output.c output.h tool.c tool.h)