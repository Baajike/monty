#include "monty.h"

/**
 * pchar - Prints the char at the top of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    int ascii_value = (*stack)->n;
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (ascii_value < 0 || ascii_value > 127)
    {
        fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    putchar((char)ascii_value);
    putchar('\n');
}
