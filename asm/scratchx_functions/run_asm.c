#include <stdio.h>
#include "../../types/scratchx_types.h"

extern double to_number(struct scratchx_string_view sv);

int main() {
	printf("%f", to_number((struct scratchx_string_view){"123.45", 6}));
	return 0;
}