#include "monty.h"

/**
 *m_push - add new node to the stack
 *@stack: pointer to stack
 *@line_number: line number
 */
void m_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(*new_node));

	(void)line_number;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(strtok(NULL, " "));
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 *m_pall - prints all the values on the stack
 *@header: pointer to stack
 *@line_number: line number
 */
void m_pall(stack_t **header, unsigned int line_number)
{
	stack_t *tmp = *header;
	(void)line_number;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 *m_pop - removes the top element of the stack
 *@stack: pointer to stack
 *@line_number: line number
 */
void m_pop(stack_t **stack, unsigned int line_number)
{

}
/**
 *m_swap - removes the top element of the stack
 *@stack: pointer to stack
 *@line_number: line number
 */
void m_swap(stack_t **stack, unsigned int line_number)
{

}
/**
 *m_pint - prints the value at the top of the stack, followed by a new line
 *@stack: pointer to stack
 *@line_number: line number
 */
void m_pint(stack_t **stack, unsigned int line_number)
{

}
