#include <stdio.h>
#include "../../types/scratchx_types.h"

extern double to_number(struct scratchx_string_view sv);
extern struct scratchx_string_view to_string(double d);

int main() {
	struct scratchx_string_view string = to_string(123.45);
	printf("%.*s", (int)string.length, string.data);
	return 0;
}