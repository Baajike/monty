#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element by the top element.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void mod(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		fclose(bus.file_pointer);
		free(bus.file_content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	s = *stack;
	if (s->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		fclose(bus.file_pointer);
		free(bus.file_content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	aux = s->next->n % s->n;
	s->next->n = aux;
	*stack = s->next;
	free(s);
}
