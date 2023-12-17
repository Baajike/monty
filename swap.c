
#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *s;
	int len = 0, aux;

	s = *stack;
	while (s)
	{
		s = s->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		fclose(bus.file_pointer);
		free(bus.file_content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	s = *stack;
	aux = s->n;
	s->n = s->next->n;
	s->next->n = aux;
}
