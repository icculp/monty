#include "monty.h"

char **margs;
char *buff;
size_t len;
stack_t *stack;
unsigned int linenumber = 1;
int line;
FILE *fd;
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

/**
* main - Main file of monty interpreter program
* @ac: Arg count
* @av: Arg array
* Return: Success or fail
*/

int main(int ac, char **av)
{
	int mi = 0, opi = 0;
	char *tok;

	margs = malloc(sizeof(char *));
	stack = malloc(sizeof(stack_t));
	if (margs == NULL || stack == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((line = getline(&buff, &len, fd)) != -1)
	{
		mi = opi = 0;
		printf("1\n");
		buff[strlen(buff) - 1] = '\0';
		tok = strtok(buff, " ");
		printf("1.5\n");
		if (tok == NULL || tok[0] == '#' || tok[0] == '\0')
		{
			linenumber++;
			continue;
		}
		while (tok != NULL)
		{
			margs[mi] = tok;
			tok = strtok(NULL, " ");
			mi++;
		}
		printf("2\n");
		if (strcmp(margs[0], "") == 0)
		{
			linenumber++;
			continue;
		}
		while (op[opi].opcode != NULL)
		{
			if (strcmp(margs[0], op[opi].opcode) == 0)
			{
				op[opi].f(&stack, linenumber);
				break;
			}
			opi++;
			if (op[opi].opcode == NULL)
			{
				dprintf(2, "L%d: unknown instruction %s\n", linenumber, margs[0]);
				exit(EXIT_FAILURE);
			}
		}
		linenumber++;
	}
	free(buff);
	free(margs);
	return (EXIT_SUCCESS);
}
