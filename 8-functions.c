#include "monty.h"

/**
* mul - Pops top and multiplies value with new top
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void mul(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	if (temp->next == NULL)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", linenumber);
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->prev->n *= temp->n;
	temp->prev->next = NULL;
	free(temp);
}
