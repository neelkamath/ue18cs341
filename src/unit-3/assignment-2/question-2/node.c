#include <stdlib.h>

#include "node.h"

struct node * node__construct(int const data)
{
    struct node * const node = malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

void node__destruct(struct node * node)
{
    free(node);
}
