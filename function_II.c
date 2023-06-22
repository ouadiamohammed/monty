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
 * _nop - doesn't do anything.
 * @stack: stack.
 * @line_number: line number
 * Return: void.
*/

void	_nop(__attribute__ ((unused))stack_t **stack,
			__attribute__ ((unused))unsigned int line_number)
{
	;
}
