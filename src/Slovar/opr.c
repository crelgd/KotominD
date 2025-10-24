
// Copyright (c) 2025 crelgd
//
// Реализация формата файла
// Содержит фукнции для управления записями

#include "Slovar.h"
#include <string.h>
#include <stdlib.h>

char* SR_Add(SR_FILE* handle, char* data, char* dtw)
{
	if (!data) return NULL;
	if (!dtw) return NULL;

	int size = strlen(dtw) + 1; // строка + \0
	char* out;
	int files_old = handle->filesize;

	handle->filesize += size;

	// создание нового массив и удаление старого
	out = (char*)malloc(sizeof(char) * handle->filesize);
	if (!out) return NULL;

	memcpy(out, data, handle->filesize);
	free(data);

	memcpy(out + files_old, dtw, size);

	return out;
}

int SR_SaveFile(SR_FILE* handle, char* data)
{
	if (!data) return NULL;

	if (fwrite(data, sizeof(char), handle->filesize, handle->file) != handle->filesize)
		return NULL;

	return 1;
}

