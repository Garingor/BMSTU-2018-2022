cmake_minimum_required(VERSION 3.15)
project(lab_04 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab_04 main.c const.h menu.c menu.h operation_stack_array.c operation_stack_array.h operation_stack_list.c operation_stack_list.h utills.c utills.h)