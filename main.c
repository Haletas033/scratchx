#include <stdio.h>

#include "parser.h"

int main(void) {
    char *buff = nullptr;
    get_file(&buff, "forever_loop.json");
    parse(&buff);
    return 0;
}
