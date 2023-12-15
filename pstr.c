#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;    
    while (current != NULL && current->n != 0 && (current->n >= 0 && current->n <= 127))
    {
        putchar((char)(current->n));
        current = current->next;
    }

    putchar('\n');
    (void)line_number; 
}
