#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "animal.h"
#include "dog.h"

void dog__speak(struct dog const * const this)
{
    printf("I'm a %s dog.\n", this->color);
}

void dog__destruct(struct dog * const this)
{
    animal__destruct(&this->super);
    free(this->color);
}

void dog__construct(struct dog *this, int const num_legs, char const * const food, char const * const color)
{
    animal__construct(&this->super, num_legs, food);
    this->color = malloc(strlen(color));
    strcpy(this->color, color);
}
