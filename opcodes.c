#include "monty.h"

/**
 * push - A function that pushes an element to the stack
 * @stack: head of the list
 * @value: data to be pushed
 */
void push(stack_t **stack, int value)
{
    stack_t *newNode;
    stack_t **stack;

    newNode = (stack_t *)malloc(sizeof(stack_t));
    if (!newNode)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->n = value;
    newNode->next = 0;

    if (!*stack)
    {
        newNode->prev = 0;
        *stack = newNode;
    }
    else
    {
        newNode->next = *stack;
        (*stack)->prev = newNode;
        *stack = newNode;
    }
}

/**
 * pall - a function that prints all the values on the stack
 */