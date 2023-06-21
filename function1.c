#include "monty.h"

/**
 * check_num - checks if the str is a num.
 * @str: string.
 * Return: 0 if the str is a num
 */
int check_num(char *str)
{
	int i = 0;

	str = strtok(str, "\n");
	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

/**
 * _push - pushes new element to teh stack.
 * @stack: Stack.
 * @line_number: line number.
 * Return: void.
 */

void _push(stack_t **stack, unsigned int line_number)
{
	int num;
	char *str;
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	str = strtok(NULL, " ");
	if (check_num(str) == -1 || str == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(str);
	new->n = num;
	new->prev = NULL;
	new->next = *stack;
	*stack = new;
}