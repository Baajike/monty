#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void push(stack_t **stack, unsigned int line_number)
{
        char *argument;
        size_t len = 0;
        ssize_t read;
        int value = atoi(argument);

    if (stack == NULL)
    {
        fprintf(stderr, "L%u: Error - Stack is NULL\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((read = getline(&argument, &len, monty_file)) == -1)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free(argument);
        exit(EXIT_FAILURE);
    }

    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free(argument);
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
    {
        (*stack)->prev = new_node;
    }

    *stack = new_node;

    free(argument);
}
