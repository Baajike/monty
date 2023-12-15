#include "monty.h"

/**
 * my_div - Divides the second top element of the stack by the top element.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */

void my_div(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n /= (*stack)->n;

    pop(stack, line_number);
}
