#include "monty.h"

/**
 * execute_instruction - Executes a Monty instruction based on its opcode.
 * @opcode: The opcode of the instruction.
 * @file: The pointer to the monty file
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */

int execute_instruction(char *file_content, stack_t **stack,
unsigned int line_number, FILE *file_pointer)
{

	instruction_t instructions[] = {
	{"push", &push},
	{"pall", &pall},
	{"pint", &pint},
	{"pop", &pop},
	{"swap", &swap},
	{"add", &add},
	{"nop", &nop},
	{"sub", &sub},
	{"div", &my_div},
	{"mul", &mul},
	{"mod", &mod},
	{"comments", &comments},
	{"pchar", &pchar},
	{"pstr", &pstr},
	{"rotl", &rotl},
	{"rotr", &rotr},
	{"stack", &stack_mode},
	{"stack", &stack_mode},
	{"queue", &queue},
	{NULL, NULL}
					};

	unsigned int i = 0;
	char *op;

	op = strtok(file_content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.argument = strtok(NULL, " \n\t");
	while (instructions[i].opcode && op)
	{
		if (strcmp(op, instructions[i].opcode) == 0)
		{	instructions[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (op && instructions[i].opcode == NULL)
	{ fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
		fclose(file_pointer);
		free(file_content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
