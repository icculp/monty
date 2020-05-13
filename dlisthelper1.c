#include "monty.h"
#include "variables.h"

/**
 * dlistint_len - returns the length of a dlistint list
 * @h: head of dlistint
 * Return: Returns number of elements in doubly linked list
 */
size_t dlistint_len(const stack_t *h)
{
	int i = 0;

	for (; h != NULL; h = h->next, i++)
	{
		;
	}
	return (i);
}

/**
 * get_dnodeint_at_index - gets a the value of a dnode_int at the index
 * @head: head of dlist
 * @index: index of node to return
 * Return: node
 */

stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 0; head; i++, head = head->next)
		if (i == index)
			return (head);
	return (NULL);
}

/**
 * sum_dlistint - returns the sum of all dlistint nodes
 * @head: head of dlist
 * Return: sum
 */
int sum_dlistint(stack_t *head)
{
	int sum;

	for (sum = 0; head; head = head->next)
		sum += head->n;
	return (sum);
}

/**
 * delete_dnodeint_at_index - deletes node at given index
 * @head: beginning of list
 * @index: index of node to be deleted
 * Return: 1 on success, -1 on failure
 */

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *search = *head;
	unsigned int i = 0;

	while (search)
	{
		if (i == index)
		{
			if (search->next)
				search->next->prev = search->prev;
			if (index > 0)
				search->prev->next = search->next;
			else if (index == 0)
			{
				search = (*head);
				(*head) = search->next;
			}
			free(search);
			return (1);
		}
		search = search->next;
		i++;
	}
	return (-1);
}
