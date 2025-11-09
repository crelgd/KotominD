
// Copyright (c) 2025 crelgd
//
// Основной файл

#ifndef _MAIN_H_
#define _MAIN_H_

#include "Slovar.h"

// Содержит просто данные из словаря для функций
typedef struct {
	SR_FILE* sr_file;
	SR_DATA* sr_data;
} MFILE;

MFILE* MLoadFile(const char* filename);

#endif
