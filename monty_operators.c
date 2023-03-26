#include "monty.h"
/**
 * f_push - function that adds node to the stack
 * @head: double head pointer to the stack
 * 
 * Return: Nothing
 * 
 */

void f_push(stack_t **head, __attribute__((unused))unsigned int line_number)
{
    unsigned int i = 0;

    i = atoi(args.arg);
    add_node(head, i);
}

/**
 * addnode
 * 
 */
void add_node(stack_t **head, int n)
{
    stack_t *new_node, *temp;

    temp = *head;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL){
        printf("Error: malloc failed");
        exit(EXIT_FAILURE);
    }
    if (temp)
    {
        temp->prev = new_node;
    }
    new_node->n = n;
    new_node->next = *head;
    new_node->prev = NULL;
    *head = new_node;
}