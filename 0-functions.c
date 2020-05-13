#include "monty.h"
#include "variables.h"

/**
*
*/

void push(void)
{
	int a;

	a = atoi(margs[1]);
	add_dnodeint_end(stack, a);
}

/**
* pall - Prints all the values on the stack, starting from the top
*/

void pall(void)
{
	stack_t *temp = stack;

	while (temp->next != NULL)
		temp = temp->next;
	while (temp != NULL)
	{
		printf("%s\n", temp->n);
		temp = temp->prev;
	}
}
