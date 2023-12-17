#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *s;
	(void)line_number;

	s = *stack;
	while (s)
	{
		if (s->n > 127 || s->n <= 0)
		{
			break;
		}
		printf("%c", s->n);
		s = s->next;
	}
	printf("\n");
}
