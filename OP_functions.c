#include "monty.h"

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

/**
 * _sub - subtracts the top element of the stack
 *        from the second top element of the stack.
 * @stack: stack.
 * @line_number: line number.
 * Return: void.
 */

void	_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *number;
	int res;

	number = *stack;
	if (!number || !(number->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	res = number->next->n - number->n;
	number->next->n = res;
	_pop(stack, line_number);
}