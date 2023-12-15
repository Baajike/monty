#include "monty.h"

/**
 * execute_instruction - Executes a Monty instruction based on its opcode.
 * @opcode: The opcode of the instruction.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */

void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number)
{
    size_t i;

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

    for (i = 0; instructions[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            instructions[i].f(stack, line_number);
            return;
        }
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
