#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animal.h"

void animal__speak(struct animal const * const this)
{
    printf("I'm an animal with %d legs.\n", this->num_legs);
}

void animal__eat(struct animal const * const this)
{
    printf("Eating %s...\n", this->food);
}

void animal__sleep()
{
    puts("Animal is sleeping...");
}

void animal__destruct(struct animal * const this)
{
    free(this->food);
}

void animal__construct(struct animal *this, unsigned const num_legs, char const * const food)
{
    this->num_legs = num_legs;
    this->food = malloc(strlen(food));
    strcpy(this->food, food);
}
