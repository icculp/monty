#include "monty.h"

monty m;


/**void ops(void)
{
	int opi = 0;


}*/

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
/**	monty m = {NULL, NULL, 0, NULL, 1, 0, NULL};*/
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

	m.margs = malloc(sizeof(char *) * 10);
	/**m.stack = NULL; malloc(sizeof(stack_t *));*/
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
	while ((m.line = getline(&m.buff, &m.len, m.fd)) != -1)
	{
		mi = opi = 0;
		printf("11\n");
		m.buff[strlen(m.buff) - 1] = '\0';
		printf("||BUFF: %s\n", m.buff);
		tok = strtok(m.buff, " ");
		printf("1.5\n");
		printf("TOKKK: %s\n", tok);
/**		printf("tok0: %c\n", tok[0]);*/
		if (tok == NULL || tok[0] == '#' || tok[0] == '\0')
		{
			printf("Ln: %d\n", m.linenumber++);
			continue;
		}
		while (tok != NULL)
		{
			m.margs[mi] = tok;
			printf("margsmi: %s, mi: %d\n", m.margs[mi], mi);
			tok = strtok(NULL, " ");
			mi++;
			if (mi > 2)
				break;
		}
		printf("22\n");
		/**ops();*/
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
		m.linenumber++;
	}
	printf("BUFF: (%s)\n", m.buff);
	free(m.buff);
	printf("Margs: (%s)\n", m.margs[0]);
	free_dlistint(m.stack);
	printf("afterfreedlist\n");
	free(m.margs);
	printf("afterfreemargs");
	return (EXIT_SUCCESS);
}
