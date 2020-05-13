#include "monty.h"
#include "variables.h"\

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
	instruction_t op[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
	};

	linenumber = 1;
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
	if (fd = -1)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((line = getline(&buff, mi, fd)) != -1)
	{
		mi = 0;
		buff[strlen(buff) - 1] = '\0';
		while((tok = strtok(buff, " ")) != NULL);
		{
			margs[mi++] = tok;
		}
		margs[mi] = NULL;
		while (op[opi].opcode != NULL)
		{
			if (strcmp(margs[0], op.opcode) == 0)
				op[opi].f(stack, linenumber);
			opi++;
			if (op[opi].opcode == NULL)
			{
				dprintf(STDERR, "L%d: unknown instruction %s\n", linenumber, margs[0]);
				exit(EXIT_FAILURE);
			}
		}
		linenumber++;
	}
	free(buff);
	free(margs);
	return(EXIT_SUCCESS);
}
