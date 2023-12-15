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
	
	stack_t *temp = *stack;

    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
    }

    if (*stack != NULL)
    {
        (*stack)->prev = temp;
    }

    if (temp != NULL)
    {
        temp->next = *stack;
    }

    if (*stack != NULL)
    {
        *stack = (*stack)->next;
        if (*stack != NULL)
        {
            (*stack)->prev = NULL;
        }
    }
}

/**
 * addqueue - Adds a node to the tail of the stack.
 * @head: Pointer to the head of the stack.
 * @n: Value to be added.
 * Return: No return.
 */
void addqueue(stack_t **head, int n)
{
    stack_t *new_node, *aux;

    aux = *head;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = n;
    new_node->next = NULL;
    if (aux)
    {
        while (aux->next)
            aux = aux->next;
    }
    if (!aux)
    {
        *head = new_node;
        new_node->prev = NULL;
    }
    else
    {
        aux->next = new_node;
        new_node->prev = aux;
    }
}

