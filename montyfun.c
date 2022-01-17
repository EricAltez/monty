#include "monty.h"

/**
 *m_push - add new node to the stack
 *@stack: pointer to stack
 *@line_number: line number
 */
void m_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int n2 = 0;
	char *argument = NULL;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	argument = strtok(NULL, DELIM);
	n2 = atoi(argument);
	if (argument == NULL || isdigit(n2) != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->n = n2;
	new_node->prev = NULL;
	if (!*stack)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
		printf("pushfun\n");
}
/**
 *m_pall - prints all the values on the stack
 *@stack: pointer to stack
 *@line_number: line number
 */
void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;
	(void)line_number;

	if (!*stack)
		return;
	aux = *stack;
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
/**
 *m_pop - removes the top element of the stack
 *@stack: pointer to stack
 *@line_number: line number
 */
void m_pop(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	printf("pop\n");
}
/**
 *m_swap - removes the top element of the stack
 *@stack: pointer to stack
 *@line_number: line number
 */
void m_swap(stack_t **stack, unsigned int line_number)
{
	int x = 0, y = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	x = (*stack)->n;
	y = (*stack)->next->n;
	(*stack)->n = y;
	(*stack)->next->n = x;
	printf("swap\n");
}
/**
 *m_pint - prints the value at the top of the stack, followed by a new line
 *@stack: pointer to stack
 *@line_number: line number
 */
void m_pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
	printf("pint\n");
}
