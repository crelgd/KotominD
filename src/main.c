#include <stdio.h>
#include <stdlib.h>
#include "Slovar.h"

// Основная функция
int main(int argc, char* argv[])
{
	SR_FILE* file = SR_OpenFile("test.txt");

	char* content = SR_GetContent(file);

	SR_DATA* data = SR_Parse(file, content);

	printf("1:%s\n2:%s\n3:%s\n", data->source, data->transcript, data->translate);

	free(data);
	free(content);
	SR_CloseFIle(file);

	return 0;
}

