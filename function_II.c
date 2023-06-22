#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack.
 * @stack: stack.
 * @line_number: line number.
 * Return: void
 */

void    _swap(stack_t **stack, unsigned int line_number)
{
	int swap;
	stack_t *number;

	number = *stack;
	if (number == NULL || number->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	swap = number->n;
	number->n = number->next->n;
	number->next->n = swap;
}

/**
 * _add - adds the top two elements of the stack.
 * @stack: stack.
 * @line_number: line number.
 * Return: void.
 */

void    _add(stack_t **stack, unsigned int line_number)
{
	int number;

	if (!*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	number = (*stack)->n;
	number += (*stack)->next->n;
	_pop(stack, line_number);
	(*stack)->n = number;

}
