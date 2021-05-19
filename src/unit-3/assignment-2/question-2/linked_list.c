#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"
#include "node.h"

struct linked_list * linked_list__construct()
{
    struct linked_list * list = malloc(sizeof(struct linked_list));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

void linked_list__append(struct linked_list * const list, int const data)
{
    struct node * node = node__construct(data);
    switch (list->length)
    {
        case 0:
            list->head = list->tail = node;
            break;
        case 1:
            list->head->next = node;
            list->tail = node;
            break;
        default:
            list->tail->next = node;
            list->tail = node;
    }
    list->length++;
}

void linked_list__display(struct linked_list const * const list)
{
    struct node const * curr = list->head;
    for (unsigned index = 0; index < list->length; index++, curr = curr->next)
    {
        printf("%d", curr->data);
        if (index < list->length - 1) printf(" ");
    }
    puts("");
}

void linked_list__destruct(struct linked_list * list)
{
    struct node const * curr = list->head;
    for (unsigned index = 0; index < list->length; index++, curr = list->head)
    {
        list->head = (struct node *) curr->next;
        node__destruct((struct node *) curr);
    }
    free(list);
}

int * linked_list__to_array(struct linked_list const * const list)
{
    int * ints = malloc(list->length * sizeof(int));
    struct node const * curr = list->head;
    for (unsigned index = 0; index < list->length; index++, curr = curr->next)
        ints[index] = curr->data;
    return ints;
}
