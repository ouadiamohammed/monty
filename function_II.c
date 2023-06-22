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
    stack_t * num;

    num = *stack;
    if (num == NULL || num->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    swap = num->n;
    num->n = num->next->n;
    num->next->n = swap;   
}
