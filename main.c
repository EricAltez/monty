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
	char *filename, *line = NULL, *token = NULL, command[20];
	int data;
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
		token = strtok(line, " ");
		if (token == NULL)
		{
			fprintf(stderr, "No token found");
			exit(EXIT_FAILURE);
		}
		strcpy(command, token);
		token = strtok(NULL, " ");
		if (token == NULL)
		{
			fprintf(stderr, "No second token found");
			exit(EXIT_FAILURE);
		}
		data = atoi(token);
	}
	fclose(fp);
	free(line);
return (0);
}
/**
 *fun_select - select function to use
 *
 *
 *
 */
void fun_select(char *command, unsigned int line_num, stack_t **header)
{
	int idx;

	instruction_t instruction_list[] = {
		{"push", m_push},
		{"pop", m_pop},
		{"pall", m_pall},
		{"swap", m_swap},
		{"pint", m_pint},
		{"nop", m_nop},
		{"add", m_add},
		{NULL, NULL}

	};

	for (idx = 0; instruction_list[idx].opcode; idx++)
	{
		if (strncmp(command, instruction_list[idx].opcode, strlen(command)) == 0)
		{
			instruction_list[idx].f(header, line_num);
			break;
		}
	}
	/* command not found */
	if (instruction_list[idx].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_num, command);
		free_stack(*header);
		command = NULL;
		exit(EXIT_FAILURE);
	}
}
