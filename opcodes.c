#include "monty.h"

/**
 * push - A function that pushes an element to the stack
 * @stack: head of the list
 * @value: data to be pushed
 */
void push(stack_t **stack, int value)
{
	stack_t *newNode;

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
 * @stack: the head of the list
 * @line_number: Number of line to catch error
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	while (top != 0)
	{
		printf("%d", top->n);
		top = top->prev;
	}
}
