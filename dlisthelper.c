#include "monty.h"

/**
 * print_dlistint - prints a doubly linked lists
 * @h: dlistint_t head
 * Return: number of elements in dlistin_t
 */
size_t print_dlistint(const dlistint_t *h)
{
	int i = 0;

	for (; h != NULL; h = h->next, i++)
	{
		printf("%d\n", h->n);
	}
	return (i);
}

/**
 * add_dnodeint - add node at beginning of dlist
 * @head: head of dlist
 * @n: data of each node
 * Return: address of new element or NULL
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = (*head);
	new->prev = NULL;

	if ((*head) != NULL)
		(*head)->prev = new;

	(*head) = new;

	return (new);
}

/**
 * add_dnodeint_end - add node to the end of a dlistint_t list
 * @head: beginning of dlistint_t
 * @n: data to insert into node
 * Return: address of the new element or NULL
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *end;
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head != NULL)
	{
		end = *head;
		while (end->next != NULL)
		{
			end = end->next;
		}
		end->next = new;
		new->prev = end;
	}
	else
	{
		new->prev = NULL;
		*head = new;
	}
	return (new);
}

/**
 * insert_dnodeint_at_index - inserts a new node at a specific index
 * @idx: index to insert at
 * @h: head of dlistint_t
 * @n: data for new node
 * Return: address to the new dnodeint or NULL on failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i;
	dlistint_t *new, *hold = *h;

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	new->n = n;

	if (idx == 0)
	{
		new->next = *h;
		new->prev = NULL;

		if (*h)
			(*h)->prev = new;

		*h = new;
		return (new);
	}

	for (i = 0; hold; i++, hold = hold->next)
		if (i == idx - 1)
		{
			new->next = hold->next;
			if (new->next)
				new->next->prev = new;
			new->prev = hold;
			hold->next = new;
			return (new);
		}
	free(new);
	return (NULL);
}

/**
 * free_dlistint - frees a dlist
 * @head: head of dlist
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *end;

	while (head != NULL)
	{
		end = head;
		head = head->next;
		free(end);
	}
}
