#include "monty.h"

/**
* add - Adds the top two elements of the stack
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void add(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;
	int sum = 0;

	if (temp->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", linenumber);
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	sum += temp->prev->n;
	sum += temp->n;
	temp->prev->n = sum;
	temp->prev->next = NULL;
	free(temp);
}
