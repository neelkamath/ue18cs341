/**
implement:
object based programming using void and void*
object oriented programmng in 'C'
*/

#include <stdio.h>
#include <stdlib.h>

#include "animal.h"
#include "dog.h"

void demo_animal();

void demo_dog();

int main()
{
    demo_animal();
    demo_dog();
    return 0;
}

void demo_animal()
{
    puts("***ANIMAL***");
    struct animal * const animal = malloc(sizeof(struct animal));
    unsigned const num_legs = 2;
    char const * const food = "duck food";
    animal__construct(animal, num_legs, food);
    animal__speak(animal);
    animal__eat(animal);
    animal__sleep();
    animal__destruct(animal);
    free(animal);
}

void demo_dog()
{
    puts("***DOG***");
    struct dog * const dog = malloc(sizeof(struct dog));
    unsigned const num_legs = 4;
    char const * const food = "dog food";
    char const * const color = "brown";
    dog__construct(dog, num_legs, food, color);
    dog__speak(dog);
    animal__eat((struct animal *) dog);
    animal__sleep();
    dog__destruct(dog);
    free(dog);
}
