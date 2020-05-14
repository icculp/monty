#include "monty.h"

/**
* ops - Performs opcode operations for monty interpreter
*/

void ops(void)
{
	int opi = 0;
	instruction_t op[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{"div", div_s},
	{"mul", mul},
	{"mod", mod},
	{"pchar", pchar},
	{"pstr", pstr},
	{NULL, NULL}
	};


		while (op[opi].opcode != NULL)
		{
			printf("333\n");
			if (strcmp(m.margs[0], op[opi].opcode) == 0)
			{
				printf("inside\n");
				printf("m: %s, opi: %d, ln: %d\n", m.margs[0], opi, m.linenumber);
				printf("MARG1: %s\n", m.margs[1]);
				op[opi].f(&m.stack, m.linenumber);
				printf("inside2\n");
				break;
			}
			opi++;
			if (op[opi].opcode == NULL)
			{
				dprintf(2, "L%d: unknown instruction %s\n", m.linenumber, m.margs[0]);
				exit(EXIT_FAILURE);
			}
		}
}
