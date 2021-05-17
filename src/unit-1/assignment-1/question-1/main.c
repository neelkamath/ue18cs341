/** make malloc and free safe */

#include <stdio.h>
#include <stdlib.h>

/** Prints the <ints> having size <n>. */
void display(int *ints, int n);

int main()
{
    int n = 3;
    int *ints = malloc(sizeof(int) * n);
    for (int i = 1; i <= n; i++)
        ints[i] = i * 10;
    puts("***BEFORE FREE***");
    display(ints, n);
    free(ints);
    puts("***AFTER FREE***");
    display(ints, n);
    return 0;
}

void display(int *ints, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", ints[i]);
    puts("");
}
