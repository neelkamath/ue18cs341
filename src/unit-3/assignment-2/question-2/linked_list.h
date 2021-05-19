#ifndef LINKED_LIST_H
#define LINKED_LIST_H
    #include "node.h"

    struct linked_list
    {
        struct node * head;
        struct node * tail;
        unsigned length;
    };

    struct linked_list * linked_list__construct();

    void linked_list__append(struct linked_list * const list, int const data);

    void linked_list__display(struct linked_list const * const list);

    void linked_list__destruct(struct linked_list * list);

    /** Returns the <list> as an array on the heap. */
    int * linked_list__to_array(struct linked_list const * const list);
#endif
