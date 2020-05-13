#include "monty.h"

/**
* swap - Swaps the values of the top two elements of stack
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void swap(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;
	int swap;

	if (temp->next == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", linenumber);
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	swap = temp->prev->n;
	temp->prev->n = temp->n;
	temp->n = swap;
}
