#include "monty.h"

/**
 * stack - Sets the format of the data to a stack (LIFO).
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	bus.lifo_flag = 0;
}
