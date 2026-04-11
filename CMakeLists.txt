cmake_minimum_required(VERSION 4.2)
project(scratchx C)

set(CMAKE_C_STANDARD 11)

add_executable(scratchx main.c
        parser/include/scratchx_parser.h
        parser/src/scratchx_parser.c
        parser/include/scratchx_target.h
        parser/include/scratchx_json.h)

target_include_directories(scratchx PRIVATE parser/include)