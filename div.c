#include "monty.h"

/**
 * my_div - Divides the second top element of the stack by the top element.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */

void my_div(stack_t **stack, unsigned int line_number)
{
	stack_t *s;
	int len = 0, temp;

	s = *stack;
	while (s)
	{
		s = s->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
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
	temp = s->next->n / s->n;
	s->next->n = temp;
	*stack = s->next;
	free(s);
}
