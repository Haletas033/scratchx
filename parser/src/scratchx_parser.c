#include "scratchx_parser.h"

#include <stdio.h>
#include <stdlib.h>

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

int parse(char **buff) {
	struct scratchx_json json = scratchx_json_initialize(*buff);
	struct key_value_pair key_value;

	while (scratchx_get_key_value(&json, &key_value) == 0) {
		printf("Key: %.*s | ", (int)key_value.key.length, key_value.key.data);
		printf("Value: %.*s\n", (int)key_value.value.length, key_value.value.data);
	}

	free(*buff);
	return 0;
}