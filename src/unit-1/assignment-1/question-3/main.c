/** time the function execution */

#include <stdio.h>
#include <time.h>
#include <unistd.h>

/** Calls <sleep> for <seconds>. */
void sleep_for(int seconds);

int main()
{
    time_t begin = time(NULL);
    sleep_for(3);
    time_t end = time(NULL);
    printf("%lds\n", end - begin);
    return 0;
}

void sleep_for(int seconds)
{
    sleep(seconds);
}
