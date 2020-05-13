#include "monty.h"

/**
* pint - Prints the value at the top of the stack
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void pint(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty", linenumber);
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	printf("%d\n", temp->n);
}
