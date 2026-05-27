#include <stdio.h>
#include "../../types/scratchx_types.h"

extern double to_number(struct scratchx_string_view sv);
extern struct scratchx_string_view to_string(double d);
extern double scratchx_round(double d);

int main() {
	printf("%f", scratchx_round(-9342.982));
	return 0;
}