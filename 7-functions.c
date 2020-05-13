#include "monty.h"

/**
* div_s - Pops top and divides value into new top
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void div_s(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	if (temp->next == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", linenumber);
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	if (temp->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", linenumber);
		exit(EXIT_FAILURE);
	}
	temp->prev->n /= temp->n;
	temp->prev->next = NULL;
	free(temp);
}
