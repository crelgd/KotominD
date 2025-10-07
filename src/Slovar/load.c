
// Copyright (c) 2025 crelgd
//
// Реализация формата файла для программы
// Содержит реализации функций для загрузки файла

#include "Slovar.h"
#include <stdlib.h>

SR_FILE* SR_OpenFile(const char* filename)
{
	SR_FILE* handle;
	
	handle = (SR_FILE*)malloc(sizeof(SR_FILE));
	if (!handle) return NULL;

	handle->file = fopen(filename, "r+");
	if (!handle->file)
	{
		free(handle);
		return NULL;
	}

	fseek(handle->file, 0, SEEK_END);
	handle->filesize = ftell(handle->file);
	fseek(handle->file, 0, SEEK_SET);

	return handle;
}

void SR_CloseFIle(SR_FILE* handle)
{
	if (handle)
	{
		fclose(handle->file);
		free(handle);
	}
}

char* SR_GetContent(SR_FILE* handle)
{
	char* out;

	out = (char*)malloc(sizeof(char) * handle->filesize);
	if (!out) return NULL;

	if (fread(out, sizeof(char), handle->filesize, handle->file) != handle->filesize)
	{
		return NULL;
	}

	return out;
}