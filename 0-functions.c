#include "monty.h"
#include "variables.h"

/**
*
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
*/

void pall(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	(void)linenumber;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
