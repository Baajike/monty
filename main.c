#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "monty.h"

/**
 * main - Entry point of the Monty program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
        FILE *monty_file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    monty_file = fopen(argv[1], "r");
    if (monty_file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, monty_file)) != -1)
    {
        line_number++;
        execute_instruction(opcode, &stack, line, line_number);
	}

    free_stack(stack);
    free(line);
    fclose(monty_file);

    return EXIT_SUCCESS;
}
