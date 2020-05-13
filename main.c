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
	
	op = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
		};
	linenumber = 1;
	margs = malloc(sizeof(char *));
	stack = malloc(sizeof(stack_t));
	if (margs == NULL || stack == NULL)
	{
		dprintf(STDERR, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (ac != 2)
	{
		dprintf(STDERR, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], r);
	if (fd = -1)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((line = getline(&buff, &len, fd)) != -1)
	{
		mi = 0;
		buff[strlen(buff) - 1] = '\0';
		while((tok = strtok(buff, " ")) != NULL);
		{
			margs[mi++] = tok;
		}
		margs[mi] = NULL;
		while (op[opi] != NULL)
		{
			if (strcmp(margs[0], op.opcode) == 0)
				op[opi].f(stack, linenumber);
			opi++;
			if (op[op1] == NULL)
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
