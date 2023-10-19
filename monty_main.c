#include "monty.h"

/**
 * main - Control function
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: integer
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack;

	if (argc < 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", strlen("USAGE: monty file\n"));
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
	stack = NULL;

	char *lineptr = NULL;
	size_t n = 0;
	int line_number = 1;
	ssize_t line;

	while (getline(&lineptr, &n, file) != -1)
	{
		line_number++;
		char *opcode = strtok(lineptr, "\t\n");

		printf("opcode: %s\n", opcode);
		if (opcode == NULL || strlen(opcode) == 0)
		{
			continue;
		}

		if (strcmp(opcode, "push") == 0)
		{

			char *sec_str = strtok(NULL, "\t\n");
			printf("2nd opcode: %s\n", sec_str);
			if (sec_str == NULL)
			{

				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free(lineptr);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			int value = atoi(sec_str);
			push(&stack, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	free(lineptr);
	fclose(file);
	exit(EXIT_FAILURE);
	return (0);
}
