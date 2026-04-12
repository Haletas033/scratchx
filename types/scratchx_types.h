#ifndef SCRATCHX_STRING_VIEW_H
#define SCRATCHX_STRING_VIEW_H
#include <stddef.h>

struct scratchx_string_view {
	const char *data;
	size_t length;
};

static struct scratchx_string_view scratchx_string_view_create(const char *data, const size_t length) {
	return (struct scratchx_string_view){data, length};
}

#endif //SCRATCHX_STRING_VIEW_H
