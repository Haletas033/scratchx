#ifndef SCRATCHX_TARGET_H
#define SCRATCHX_TARGET_H

#include <stddef.h>
#include <stdbool.h>
#include "scratchx_json.h"

// Inclusive of \0
#define SCRATCHX_ID_LEN 22
#define SCRATCHX_ASSET_ID_LEN 34
#define SCRATCHX_DATA_FORMAT_LEN 4

enum scratchx_variable_type {
	SCRATCHX_VAR_NUMBER,
	SCRATCHX_VAR_STRING
};

union scratchx_variable_value {
	double number;
	struct scratchx_string_view string;
};

struct scratchx_variable {
	union scratchx_variable_value value;
	enum scratchx_variable_type type;
	char id[SCRATCHX_ID_LEN];
	struct scratchx_string_view name;
};

struct scratchx_block {
	char id[SCRATCHX_ID_LEN];
	char next[SCRATCHX_ID_LEN];
	char parent[SCRATCHX_ID_LEN];
	struct scratchx_key_value_pair *inputs;
	struct scratchx_key_value_pair *fields;
	struct scratchx_string_view opcode;
};

struct scratchx_costume {
	int rotation_center_x;
	int rotation_center_y;
	char data_format[SCRATCHX_DATA_FORMAT_LEN];
	char asset_id[SCRATCHX_ASSET_ID_LEN];
	struct scratchx_string_view name;
};

struct scratchx_sound {
	int rate;
	int samples;
	char data_format[SCRATCHX_DATA_FORMAT_LEN];
	char asset_id[SCRATCHX_ASSET_ID_LEN];
	struct scratchx_string_view name;
};

struct scratchx_sprite {
	struct scratchx_variable *variables;
	size_t variables_count;
	struct scratchx_block *blocks;
	size_t blocks_count;
	struct scratchx_costume *costumes;
	size_t costumes_count;
	struct scratchx_sound *sounds;
	size_t sounds_count;
	char *name;
	char *tts_language;
	int default_costume;
	int volume;
	int layer_order;
	int tempo;
	int video_transparency;
	bool is_stage;
	bool video_state;
};

struct scratchx_target {
	struct scratchx_sprite *sprites;
	size_t sprites_count;
};

#endif //SCRATCHX_TARGET_H
