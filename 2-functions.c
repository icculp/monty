#include "monty.h"

/**
* pop - Removed the top element of the stack
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void pop(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", linenumber);
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->prev->next = NULL;
	free(temp);
}
