#include "monty.h"

/**
* push - Adds values to top of the stack
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void push(stack_t **stack, unsigned int linenumber)
{
	int a;

	(void)linenumber;
	a = atoi(margs[1]);
	add_dnodeint_end(stack, a);
}

/**
* pall - Prints all the values on the stack, starting from the top
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void pall(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	(void)linenumber;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
