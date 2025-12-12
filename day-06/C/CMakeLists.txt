cmake_minimum_required(VERSION 4.0)
project(weight C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

# main program
add_executable(weight
        main.c)