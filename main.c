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
	char *filename;
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
	f_reader(fp, op_list);
	fclose(fp);
return (0);
}
/**
 *f_reader - reads and tokenize file line by line
 *@fp: file
 *@op_list: list of functions
 *Return: 0
 */
int f_reader(FILE *fp, instruction_t op_list[])
{
	char *line = NULL, *token = NULL;
	unsigned int line_number = 0;
	size_t len = 0;
	int i = 0, check = 0, tokenlen = 0, tokencmp = 0;
	int oplen = 0;
	stack_t *stack = NULL;

	while (1)
	{
		if (getline(&line, &len, fp) == -1)
		{
			free(line);
			break;
		}
		line_number++;
		token = strtok(line, DELIM);
		i = 0, check = 0;
		if (token)
		{
			while (op_list[i].opcode)
			{
				tokenlen = strlen(token);
				oplen = strlen(op_list[i].opcode);
				tokencmp = strcmp(token, op_list[i].opcode);
				if ((tokenlen == oplen) && (tokencmp == 0))
				{
					op_list[i].f(&stack, line_number);
					check = 1;
				}
				i++;
			}
			if (check == 0)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
				exit(EXIT_FAILURE);
			}
		}
	}
	free(line);
	return (0);
}
