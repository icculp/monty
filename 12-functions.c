#include "monty.h"

/**
* pstr - Prints ascii value of values, starting from top
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void pstr(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	(void)linenumber;
	if (temp == NULL)
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		printf("%c", temp->n);
		temp = temp->prev;
	}
	printf("\n");
}
