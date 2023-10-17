#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

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
    char *lineptr = NULL;
    size_t n = 0;
    int line_number = 1;
    ssize_t line;

    line = getline(&lineptr, &n, file);
    while (line != -1)
    {
        char *opcode = strtok(lineptr, "\t\n");
        printf("opcode: %s\n", opcode);
        if (opcode == NULL || strlen(opcode) == 0)
        {
            continue;
        }
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        free(lineptr);
        exit(EXIT_FAILURE);
        line_number++;
    }
    return (0);
}