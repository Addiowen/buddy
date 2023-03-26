#include "monty.h"
/**
 * @file opcode_execution.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
int opcode_execution(char *content, stack_t **stack, __attribute__((unused))FILE *file, unsigned int line_number)
{
    instruction_t opst[] = {
        {"push", f_push},
        /* {"pall", f_pall}, */
        {NULL, NULL}
    };
    char *op;
    unsigned int i = 0;

    op = strtok(content, "\n\t");
    if (op && op[0] == '#')
        return (0);
    args.arg = strtok(NULL, "\n\t");
    while (opst[i].opcode && op){
        if (strcmp(op, opst[i].opcode) == 0){
            opst[i].f(stack, line_number);
        }
        i++;
    }
    return (1);
}