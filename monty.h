#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STACK
#define STACK

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
#endif

/** dlisthelper.c */
size_t print_dlistint(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n);
void free_dlistint(stack_t *head);

/** dlisthelper.c */
size_t dlistint_len(const stack_t *h);
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);
int sum_dlistint(stack_t *head);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);

/** 0-functions.c */
void push(stack_t **stack, unsigned int linenumber);
void pall(stack_t **stack, unsigned int linenumber);

#endif
