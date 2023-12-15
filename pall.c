#include "monty.h"

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void pall(stack_t **stack, unsigned int line_number)
{

        (void)line_number;

        stack_t *current = *stack;

    if (current == NULL)
        return;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
