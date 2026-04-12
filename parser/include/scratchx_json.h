/*
This JSON parser is linear and stateful therefore you must walk the entire JSON in order instead of finding specific elements
This design is used, as the project requires the scratch project's JSON to be read into a struct
*/

#ifndef SCRATCHX_JSON_H
#define SCRATCHX_JSON_H

#include <stddef.h>
#include "scratchx_types.h"

struct scratchx_key_value_pair {
	struct scratchx_string_view key;
	struct scratchx_string_view value;
};

struct scratchx_json {
	char *text;
	size_t pos;
};

struct scratchx_json scratchx_json_initialize(const char *text);
int scratchx_get_key_value(struct scratchx_json *json, struct scratchx_key_value_pair *key_value_buff);
int scratchx_enter_value(struct scratchx_json *json);
void scratchx_json_destroy(struct scratchx_json *json);

#endif //SCRATCHX_JSON_H
