#include "monty.h"

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 * Return: No return.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	bus.lifo_flag = 1;
}

/**
 * addqueue - Adds a node to the tail of the stack.
 * @stack: Pointer to the head of the stack.
 * @n: Value to be added.
 * Return: No return.
 */
void addqueue(stack_t **stack, int n)
{
	stack_t *new_node, *temp;

	temp = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp)
	{
	while (temp->next)
	temp = temp->next;
	}
	if (!temp)
	{
	*stack = new_node;
	new_node->prev = NULL;
	}
	else
	{
	temp->next = new_node;
	new_node->prev = temp;
	}
}

