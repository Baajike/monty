#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Entry point of the Monty program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	char *file_content;
	FILE *file_pointer;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_pointer = fopen(argv[1], "r");
	bus.file_pointer = file_pointer;
	if (!file_pointer)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		file_content = NULL;
		read_line = getline(&file_content, &size, file_pointer);
		bus.file_content = file_content;
		line_number++;
		if (read_line > 0)
		{
			execute_instruction(file_content, &stack, line_number, file_pointer);
		}
		free(file_content);
	}
	free_stack(stack);
	fclose(file_pointer);
return (0);
}
