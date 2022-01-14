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
	printf("p1");
	filename = argv[1];
	printf("p2");
	fp = fopen(filename, "r");
	printf("p3");
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
	char *line = NULL;
	unsigned int line_number = 0;
	char *token = NULL;
	size_t len = 0;
	int i = 0, flag = 0;
	stack_t *stack = NULL;

	while (getline(&line, &len, fp) != -1)
	{
		token = strtok(line, DELIM);
		line_number++;
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
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	return (0);
}
