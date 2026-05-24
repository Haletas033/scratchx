#ifndef SCRATCHX_STRING_VIEW_H
#define SCRATCHX_STRING_VIEW_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct scratchx_string_view {
	const char *data;
	size_t length;
};

static struct scratchx_string_view scratchx_string_view_create(const char *data, const size_t length) {
	return (struct scratchx_string_view){data, length};
}

static int scratchx_string_view_to_number(struct scratchx_string_view sv, double* number_buff) {
	// Add null-terminator to the string view
	char string[sv.length+1];
	memcpy(string, sv.data, sv.length);
	string[sv.length] = '\0';

	char* end_ptr;
	double number = strtod(string, &end_ptr);
	if (end_ptr != string + sv.length) return 1;
	*number_buff = number;
	return 0;
}

#endif //SCRATCHX_STRING_VIEW_H
