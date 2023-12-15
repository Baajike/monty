#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    (void)line_number;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = *stack;
    (*stack)->prev = temp;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
}
