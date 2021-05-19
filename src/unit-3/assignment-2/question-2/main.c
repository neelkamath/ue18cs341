/*
change C list to an array list. Modify the implementation suitable without affecting
	the client code
*/

#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

int main()
{
    struct linked_list * const list = linked_list__construct();
    for (int element = -2; element < 3; element++)
        linked_list__append(list, element);
    linked_list__display(list);
    int const * const ints = linked_list__to_array(list);
    for (unsigned index = 0; index < list->length; index++)
    {
        printf("%d", ints[index]);
        if (index != list->length - 1) printf(" ");
    }
    puts("");
    free((int *) ints);
    linked_list__destruct(list);
    return 0;
}
