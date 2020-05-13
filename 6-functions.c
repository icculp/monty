#include "monty.h"

/**
* sub - Pops top and subtracts value from new top
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void sub(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	if (temp->next == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", linenumber);
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->prev->n -= temp->n;
	temp->prev->next = NULL;
	free(temp);
}
