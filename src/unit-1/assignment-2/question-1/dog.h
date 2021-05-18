#include "animal.h"

#ifndef DOG_H
#define DOG_H
    struct dog
    {
        struct animal super;
        char *color;
    };

    void dog__speak(struct dog const * const this);

    void dog__destruct(struct dog * const this);

    void dog__construct(struct dog *this, int const num_legs, char const * const food, char const * const color);
#endif
