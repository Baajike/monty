#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *s;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file_pointer);
		free(bus.file_content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	s = *stack;
	*stack = s->next;
	free(s);
}
