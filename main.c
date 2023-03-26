#include "monty.h"

/***/

arg_t args = { NULL, NULL, NULL};
int main(int argc, char *argv[])
{
    FILE *file;
    char *content;
    size_t size = 0;
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    args.file = file;
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (read_line > 0)
    {
        content = NULL;
        read_line = _getline(&content, &size, file);
        args.content = content;
        line_number++;
        if (read_line > 0)
            opcode_execution(content, &stack, file, line_number);
        free(content);
        
    }
    /** free stack */
    fclose(file);
    return (0);
}