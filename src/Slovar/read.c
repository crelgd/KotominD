
// Copyright (c) 2025 crelgd
//
// Реализация формата файла
// Содержит фукнции для чтения содержания файла и его парсинг

#include "Slovar.h"
#include <stdlib.h>
#include <string.h>

// out - весь массив
// in - массив в который нужно записать
// stop - знак для остановки
void cpArray(char* out, char* in, char stop, int linesize, int* cur_pos, int* element_size)
{
	int i;
	for (i = 0; i < linesize; i++)
	{
		if (out[i] == stop) break;
		in[i] = out[i];
	}
	in[i] = '\0';
	*cur_pos += i + 1;
	*element_size = i + 1;
}

SR_DATA* SR_Parse(SR_FILE* handle, char* sr_data)
{
	SR_DATA* data = (SR_DATA*)malloc(sizeof(SR_DATA));

	int element_size;
	int pos = 0;
	char maxLine[MAX_LINE] = { 0 };
	cpArray(sr_data + pos, maxLine, ':', MAX_LINE, &pos, &element_size);
	memcpy(data->source, maxLine, element_size);
	cpArray(sr_data + pos, maxLine, ';', MAX_LINE, &pos, &element_size);
	memcpy(data->transcript, maxLine, element_size);
	cpArray(sr_data + pos, maxLine, '.', MAX_LINE, &pos, &element_size);
	memcpy(data->translate, maxLine, element_size);

	return data;
}

// дальше добавить в SR_Parse поддержку многострок