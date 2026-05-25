section .data
    msg db "Hello, world!", 10
    len equ $ - msg

section .text
    global to_number

to_number:
    cmp rsi, 256
    jl small_string

    jmp heap_string

    ret

small_string:
    sub rsp, 256

heap_string:
