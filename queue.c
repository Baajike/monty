#include "monty.h"

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void queue(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    stack_t *temp = *stack;
    stack_t *last = *stack;

    while (last->next != NULL)
        last = last->next;

    last->next = *stack;
    (*stack)->prev = last;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
}

