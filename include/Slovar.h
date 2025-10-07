
// Copyright (c) 2025 crelgd
//
// Формат файла для программы
// Нужно чтоб вводить в программу слова которые нужно запомнить
//
// Пример записи
//	休む:yasumu;отдыхать.
// 
// Если точнее: слово для запоминания: как произноситься; перевод.

#ifndef _SLOVAR_H_
#define _SLOVAR_H_

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_LINE		1024

// Структура содержащая данные о файле
// Заметка* добавить long к filesize
typedef struct {
	const char* name;	// имя файла которое нужно загрузить\или уже загруженное
	int filesize;		// размер файла в байтах
	FILE* file;			// дескриптов для файла
} SR_FILE;

// Структура содержащая данные о парсинге файла
// Заметка* переводить в UTF-8 если это нужно пользователю
typedef struct {
	char* source[MAX_LINE];			// их примера слово 休む
	char* transcript[MAX_LINE];		// транскрипция
	char* translate[MAX_LINE];		// перевод
} SR_DATA;

SR_FILE* SR_OpenFile(const char* filename);

void SR_CloseFIle(SR_FILE* handle);

char* SR_GetContent(SR_FILE* handle);

SR_DATA* SR_Parse(SR_FILE* handle, char* sr_data);

#endif

