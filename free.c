#include "monty.h"

/**
 * free_stack - frees the stack.
 * @head: pointer to the stack head.
 * Return: void.
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
