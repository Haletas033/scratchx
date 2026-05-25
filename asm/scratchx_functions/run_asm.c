#include <stdio.h>
#include "../../types/scratchx_types.h"

extern double to_number(struct scratchx_string_view sv);

int main() {
	to_number((struct scratchx_string_view){"Hello", 5});
	return 0;
}