/*
This JSON parser is linear and stateful therefore you must walk the entire JSON in order instead of finding specific elements
This design is used, as the project requires the scratch project's JSON to be read into a struct
*/

#include "scratchx_json.h"

#include <stdlib.h>
#include <string.h>

struct scratchx_json scratchx_json_initialize(const char *text) {
	char *copy = strdup(text);
	if (copy == NULL) {
		return (struct scratchx_json){NULL, 0};
	}
	return (struct scratchx_json){copy, 0};
}

int scratchx_enter_value(struct scratchx_json *json) {
	if (json->text == NULL) return -1;
	// Search until the next key is found
	while (json->text[json->pos] != '\0' && json->text[json->pos] != '"') {
		json->pos++;
       }
	return json->text[json->pos] != '\0';
}

int scratchx_get_key_value(struct scratchx_json *json, struct key_value_pair* key_value_buff) {
	scratchx_enter_value(json);

	size_t key_length = 0;
	size_t value_length = 0;

	// Step into the key
	json->pos++;

	const char* key_start = &json->text[json->pos];

	while (json->text[json->pos] != '"' && json->text[json->pos] != '\0') {
		json->pos++;
		key_length++;
	}
	if (json->text[json->pos] == '\0') return 1;
	key_value_buff->key = scratchx_string_view_create(key_start, key_length);

	// Step out of the key
	json->pos++;

	// Step into the value
	while (json->text[json->pos] == ' ' || json->text[json->pos] == '\t' || json->text[json->pos] == ':') {
		json->pos++;
	}

	const char* value_start = &json->text[json->pos];

	int in_quotes = json->text[json->pos] == '"';

	while (json->text[json->pos] != '\0' && (in_quotes || json->text[json->pos] != '\n' && json->text[json->pos] != ',' && json->text[json->pos] != ']' && json->text[json->pos] != '}')) {
		json->pos++;
		value_length++;
		if (json->text[json->pos] == '"') in_quotes = !in_quotes;
	}
	if (json->text[json->pos] == '\0') return 1;
	key_value_buff->value = scratchx_string_view_create(value_start, value_length);
	return 0;
}

void scratchx_json_destroy(struct scratchx_json *json) {
	free(json->text);
	json->text = NULL;
}