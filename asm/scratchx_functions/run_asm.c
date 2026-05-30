#include <stdio.h>
#include <time.h>

#include "../../types/scratchx_types.h"

extern double to_number(struct scratchx_string_view sv);
extern struct scratchx_string_view to_string(double d);
extern double scratchx_round(double d);
extern struct scratchx_string_view str_join(struct scratchx_string_view sv1, struct scratchx_string_view sv2);
extern struct scratchx_string_view char_at(struct scratchx_string_view sv, unsigned int index);
extern int str_contains(struct scratchx_string_view haystack, struct scratchx_string_view needle);
extern double scratchx_random(double min, double max, int is_double);

int main() {
	srand48(time(NULL));
	printf("%f", scratchx_random(1, 100, 0));
	return 0;
}