#include "monty.h"

/** global struct with important monty data */
monty m;

/**
* main - Main file of monty interpreter program
* @ac: Arg count
* @av: Arg array
* Return: Success or fail
*/

int main(int ac, char **av)
{
	m.linenumber = 1;
	m.margs = malloc(sizeof(char *) * 10);
	if (m.margs == NULL)/**|| stack == NULL)*/
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	m.fd = fopen(av[1], "r");
	if (m.fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	montyparser();

	printf("BUFF: (%s)\n", m.buff);
	free(m.buff);
	printf("Margs: (%s)\n", m.margs[0]);
	free_dlistint(m.stack);
	printf("afterfreedlist\n");
	free(m.margs);
	printf("afterfreemargs");
	return (EXIT_SUCCESS);
}
