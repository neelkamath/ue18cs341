#ifndef NODE_H
#define NODE_H
    struct node
    {
        int data;
        struct node const * next;
    };

    struct node * node__construct(int const data);

    void node__destruct(struct node * node);
#endif
