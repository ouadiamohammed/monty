#include "main.h"

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