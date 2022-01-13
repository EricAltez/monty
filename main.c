#include "monty.h"
/**
 *main - entry point for monty interpreter
 *@argc: argument number
 *@argv: arguments array
 *Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *fileus;
	char *filename;
	stack_t *header = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	fileus = fopen(filename, "r");

	if (fileus == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}





return (0);
}

/**
 *filereder - read file lines and pass them to fun_select
 *
 *
 *
 */
int filereader(FILE *fileus, stack_t **header)
{



}
