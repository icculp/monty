#include "monty.h"

/**
* pchar - Prints ascii value of top node in the stack
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void pchar(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", linenumber);
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	if (temp->n < 0 || temp->n > 127)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", linenumber);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}
