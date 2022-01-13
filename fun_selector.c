#include "monty.h"
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
