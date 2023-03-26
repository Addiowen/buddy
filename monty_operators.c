#include "monty.h"
#include <stdlib.h>
/**
 * f_push - function that adds node to the stack
 * @head: double head pointer to the stack
 * 
 * Return: Nothing
 * 
 */

void f_push(stack_t **head, __attribute__((unused))unsigned int line_number)
{
    unsigned int i = 0, m = 0, flag = 0;

    if (args.arg){
        if (args.arg[0] == '-')
            m++;
        for (; args.arg[m] != '\0'; m++){
            if (args.arg[m] > 57 || args.arg[m] < 48)
                flag = 1;
        }
        if (flag == 1){
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            fclose(args.file);
            free(args.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(args.file);
        free(args.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    i = atoi(args.arg);
    add_node(head, i);
}

/**
* f_pall - function that prints everything in the stack
* @head: double head pointer to the stack
* @line_number: unused line count
*
* Return: nothing
*/
void f_pall(stack_t **head, unsigned int line_number){
    stack_t *h;
    (void)line_number;

    h = *head;
    if (h == NULL)
        return;
    while (h){
        printf("%d\n", h->n);
        h = h->next;
    }
}
