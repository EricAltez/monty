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
	char *filename, *line = NULL, *line_ad;

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
	*line_ad = *line;
	f_reader(line_ad, fp);
	fclose(fp);
	free(line);
return (0);
}
/**
 *f_reader - reads and tokenize file line by line
 *@line: line pointer
 *@fp: file
 *Return: 0
 */
int f_reader(char *line, FILE *fp)
{
	unsigned int line_number = 0;
	char *token = NULL;
	size_t len = 0;
	int i;
	stack_t *stack;
	instruction_t op_list[] = {
		{"push", m_push},
		{"pop", m_pop},
		{"pall", m_pall},
		{"swap", m_swap},
		{"pint", m_pint},
		{"nop", m_nop},
		{"add", m_add},
		{NULL, NULL}
	};

	while (getline(&line, &len, fp) != -1)
	{
		token = strtok(line, DELIM);
		if (token == NULL)
		{
			fprintf(stderr, "No token found");
			exit(EXIT_FAILURE);
		}
		while (op_list[i].opcode)
		{
			if (strcmp(token, op_list[i].opcode))
			{
				op_list[i].f(&stack, line_number);
			}
			i++;
		}
		/* if */
	}
	return (0);
}
