#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *current;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    current = *stack;

    if (current->next != NULL)
    {
        *stack = current->next;
        current->next->prev = NULL;
    }
    else
    {
        *stack = NULL;
    }

    free(current);
}
