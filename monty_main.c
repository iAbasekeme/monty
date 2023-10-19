#include "monty.h"

extern void push(stack_t **stack, int value);

int main(int argc, char *argv[])
{
	FILE *file;
	if (argc < 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", strlen("USAGE: monty file"));
		exit(EXIT_FAILURE);
	}
	else
	{
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}

	stack_t *stack = NULL;

	char *lineptr = NULL;
	size_t n = 0;
	int line_number = 1;
	ssize_t line;

	while (line = getline(&lineptr, &n, file) != -1)
	{
		char *opcode = strtok(lineptr, "\t\n");
		printf("opcode: %s\n", opcode);
		if (opcode == NULL || strlen(opcode) == 0)
		{
			continue;
		}
		char *sec_str = strtok(NULL, "\t\n");
		if (sec_str == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer %s\n", line_number);
			free(lineptr);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		int value = atoi(sec_str);

		if (strcmp(opcode, 'push') == 0)
		{
			push(&stack, value);
		}
		else if (strcmp(opcode, 'pall') == 0)
		{
			pall(&stack, line_number);
		}
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		free(lineptr);
		line_number++;
	}
	free(lineptr);
	fclose(file);
	exit(EXIT_FAILURE);
	return (0);
}