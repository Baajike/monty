#include "monty.h"

/**
 * stack - Sets the format of the data to a stack (LIFO).
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void stack(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    stack_t *last = *stack;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    last = *stack;

    while (last->next != NULL)
        last = last->next;

    last->next = *stack;
    (*stack)->prev = last;
    *stack = last->next;
    (*stack)->prev = NULL;
}
