cmake_minimum_required(VERSION 4.2)
project(scratchc C)

set(CMAKE_C_STANDARD 23)

add_executable(scratchc main.c
        parser/include/parser.h
        parser/src/parser.c)

target_include_directories(scratchc PRIVATE parser/include)