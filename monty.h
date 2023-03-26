#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/***/
typedef struct arg_s {
    char *arg;
    FILE *file;
    char *content;
} arg_t;
extern arg_t args;
void f_push(stack_t **head, unsigned int line_number);
void f_pall(stack_t **head, unsigned int line_number);
void add_node(stack_t **head, int n);
int opcode_execution(char *content, stack_t **stack, FILE *file, unsigned int line_number);
int _getline(char **line, size_t *n, FILE *stream);
#endif
