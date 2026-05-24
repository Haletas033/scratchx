#include "scratchx_parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scratchx_target.h"
#include "scratchx_json.h"

int get_file(char **buff, const char *filename) {
	FILE *file = fopen(filename, "r");
	if (file == NULL) goto err;

	// Get length of the file
	fseek(file, 0, SEEK_END);
	long filesize = ftell(file);
	if (filesize < 0) goto err_close;

	// Allocate memory for the buffer
	char *tmp = malloc(filesize+1);
	if (tmp == NULL) goto err_close;
	*buff = tmp;

	// Fill the buffer with the file's contents
	rewind(file);
	if (fread(*buff, 1, filesize, file) < filesize) goto err_free;
	(*buff)[filesize] = '\0';

	fclose(file);
	return 0;
err_free:
	free(tmp);
	*buff = NULL;
err_close:
	fclose(file);
err:
	return -1;
}

struct scratchx_target scratchx_generate_target(struct scratchx_json *json) {
	struct scratchx_target target = {0};
	SCRATCHX_SAFE_GET(json, "targets", key_not_found_err);
	target.sprites = malloc(sizeof(struct scratchx_sprite));
	target.sprites_count++;
	target.sprites[0].is_stage = strncmp(SCRATCHX_SAFE_GET(json, "isStage", key_not_found_err).data, "true", 4) ? 1 : 0;
	target.sprites[0].name = SCRATCHX_SAFE_GET(json, "name", key_not_found_err);

	// Get all variables
	SCRATCHX_SAFE_GET(json, "variables", key_not_found_err);
	while (1) {
		target.sprites->variables = malloc(sizeof(struct scratchx_variable));
		target.sprites->variables_count++;
		struct scratchx_key_value_pair variable;
		scratchx_get_key_value(json, &variable);
		strncpy(target.sprites->variables[0].id, variable.key.data, SCRATCHX_ID_LEN);
		printf("%s\n", target.sprites[0].variables[0].id);
		printf("%.*s\n", (int)variable.value.length, variable.value.data);
		scratchx_enter_value(json);
		break;
	}

	// Get all lists
	SCRATCHX_SAFE_GET(json, "lists", key_not_found_err);

	// Get all broadcasts
	SCRATCHX_SAFE_GET(json, "broadcasts", key_not_found_err);

	// Get all blocks
	SCRATCHX_SAFE_GET(json, "block", key_not_found_err);

	// Get all comments
	SCRATCHX_SAFE_GET(json, "comments", key_not_found_err);

	double currentCostume = 0;
	scratchx_string_view_to_number(SCRATCHX_SAFE_GET(json, "currentCostume", key_not_found_err), &currentCostume);
	target.sprites[0].default_costume = (int)currentCostume;

	// Get all costumes
	SCRATCHX_SAFE_GET(json, "costumes", key_not_found_err);

	// Get all sounds
	SCRATCHX_SAFE_GET(json, "sounds", key_not_found_err);

	double volume = 0;
	double layer_order = 0;
	double tempo = 0;
	double video_transparency = 0;
	scratchx_string_view_to_number(SCRATCHX_SAFE_GET(json, "volume", key_not_found_err), &volume);
	scratchx_string_view_to_number(SCRATCHX_SAFE_GET(json, "layerOrder", key_not_found_err), &layer_order);
	scratchx_string_view_to_number(SCRATCHX_SAFE_GET(json, "tempo", key_not_found_err), &tempo);
	scratchx_string_view_to_number(SCRATCHX_SAFE_GET(json, "videoTransparency", key_not_found_err), &video_transparency);
	target.sprites[0].volume = (int)volume;
	target.sprites[0].layer_order = (int)layer_order;
	target.sprites[0].tempo = (int)tempo;
	target.sprites[0].video_transparency = (int)video_transparency;

	printf("%.*s", (int)target.sprites[0].name.length, target.sprites[0].name.data);
	return target;

key_not_found_err:
	return (struct scratchx_target){NULL, 0};
}

void scratchx_destroy_target(struct scratchx_target *target) {

}

int parse(char **buff) {
	struct scratchx_json json = scratchx_json_initialize(*buff);
	scratchx_generate_target(&json);

	free(*buff);
	return 0;
}