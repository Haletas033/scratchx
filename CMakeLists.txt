cmake_minimum_required(VERSION 4.2)
project(scratchx C)

set(CMAKE_C_STANDARD 23)

add_executable(scratchx main.c
        parser/include/parser.h
        parser/src/parser.c)

target_include_directories(scratchx PRIVATE parser/include)