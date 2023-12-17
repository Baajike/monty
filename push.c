#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n, j = 0;
	int flag = 0;

	if (bus.argument)
	{
		if (bus.argument[0] == '-')
			j++;
		for (; bus.argument[j] != '\0'; j++)
		{
			if (bus.argument[j] > 57 || bus.argument[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file_pointer);
			free(bus.file_content);
			free_stack(*stack);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file_pointer);
		free(bus.file_content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	n = atoi(bus.argument);
	if (bus.lifo_flag == 0)
		addnode(stack, n);
	else
		addqueue(stack, n);
}
