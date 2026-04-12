#include <stdio.h>

#include "scratchx_parser.h"

int main(void) {
	char *buff = NULL;
	get_file(&buff, "test_jsons/forever_loop.json");
	parse(&buff);
	return 0;
}
