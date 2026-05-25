cmake_minimum_required(VERSION 4.2)
project(scratchx C)

set(CMAKE_C_STANDARD 11)

enable_language(ASM_NASM)
file(GLOB ASM_SOURCES "asm/scratchx_functions/*.asm")

add_executable(scratchx main.c
        parser/include/scratchx_parser.h
        parser/src/scratchx_parser.c
        parser/include/scratchx_target.h
        parser/include/scratchx_json.h
        parser/src/scratchx_json.c
        types/scratchx_types.h
        ${ASM_SOURCES}
)

target_include_directories(scratchx PRIVATE parser/include types)

add_executable(asm_testing
        asm/scratchx_functions/run_asm.c
        ${ASM_SOURCES}
)

target_include_directories(asm_testing PRIVATE parser/include types)

file(COPY test_jsons DESTINATION ${CMAKE_BINARY_DIR})