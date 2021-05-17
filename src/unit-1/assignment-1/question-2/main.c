/** counts the number of times a function is called */

#include <stdio.h>

/** Prints the number of times this function has been called. */
void display();

int main()
{
    for (int i = 0; i < 3; i++)
        display();
    return 0;
}

void display()
{
    static int count = 0;
    count++;
    printf("%d\n", count);
}
