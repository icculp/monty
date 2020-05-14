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
	printf("m.ln: %d\n", m.linenumber);
	printf("mbuf: %s\n", m.buff);
	printf("MAYBE\n");
	printf("MARG111: %s", m.margs[0]);
	a = atoi(m.margs[1]);
	printf("APPLE (%d)\n", a);
	add_dnodeint_end(stack, a);
	printf("Orange (%d)\n", a);
}

/**
* pall - Prints all the values on the stack, starting from the top
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void pall(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	printf("???\n");
/*	print_dlistint(*stack); */
	(void)linenumber;
	if (!temp)
		return;
	while (temp->next != NULL)
		temp = temp->next;
	printf("Pops\n");
	while (temp->prev != NULL)
	{
		printf("poppy\n");
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
	printf("pop\n");
	printf("TEMPal: %d\n", temp->n);
	printf("!!!\n");
/*	print_dlistint(*stack); */
}

/**
* pint - Prints the value at the top of the stack
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void pint(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty", linenumber);
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	printf("%d\n", temp->n);
}

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
	if (temp->prev != NULL)
		temp->prev->next = NULL;
	free(temp);
	if (temp->prev == NULL && temp->next == NULL)
		*stack = NULL;
}

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