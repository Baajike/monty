#include "monty.h"

/**
 * free_stack - Frees a stack.
 * @stack: Pointer to the head of the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;
	temp = stack;

	while (stack)

	{
	temp = stack->next;
	free(stack);
	stack = temp;
	}
}
