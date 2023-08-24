
#include "monty.h"
#include <string.h>

void free_s(stack_t **stack);
int init_s(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_s - frees the stack
 * @stack: pointer to top stack or bottom queue
 * Return: none
 */
void free_s(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * init_s - initializes the stack
 * @stack: pointer to stack
 * Return: Succes or failure
 */
int init_s(stack_t **stack)
{
	stack_t *st;

	st = malloc(sizeof(stack_t));
	if (st == NULL)
		return (err_malloc());
	st->n = STACK;
	st->prev = NULL;
	st->next = NULL;
	*stack = st;
	return (EXIT_SUCCESS);
}

/**
 * check_mode - check for the active mode
 * @stack: pointer to top (stack) or bottom (queue)
 * Return: mode or -2
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
