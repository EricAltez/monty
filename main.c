#include "monty.h"
/**
 *main - entry point for monty interpreter
 *@argc: argument number
 *@argv: arguments array
 *Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *filename, *line = NULL;
	stack_t *header = NULL;
	size_t len = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, fp) != -1)
	{
		fun_select(strtok(*line));
	}



	fclose(fp);
	free(line);
return (0);
}


