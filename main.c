#include "monty.h"
#include "variables.h"

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
	char **margs = malloc(sizeof(char *));
	char *buff;
	size_t len;
	stack_t *stack = malloc(sizeof(stack_t));
	unsigned int linenumber = 1;
	int line;
	FILE *fd;
	instruction_t op[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
	};

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
		mi = 0;
		buff[strlen(buff) - 1] = '\0';
		while((tok = strtok(buff, " ")) != NULL);
		{
			margs[mi++] = strdup(tok);
		}
		margs[mi] = NULL;
		while (op[opi].opcode != NULL)
		{
			if (strcmp(margs[0], op[opi].opcode) == 0)
				op[opi].f(&stack, linenumber);
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
	return(EXIT_SUCCESS);
}
