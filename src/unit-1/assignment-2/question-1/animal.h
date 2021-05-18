#ifndef ANIMAL_H
#define ANIMAL_H
    struct animal
    {
        unsigned num_legs;
        char *food;
    };

    void animal__speak(struct animal const * const this);

    void animal__eat(struct animal const * const this);

    void animal__sleep();

    void animal__destruct(struct animal * const this);

    void animal__construct(struct animal *this, unsigned const num_legs, char const * const food);
#endif
