#ifndef TURTLE_H
#define TURTLE_H
#include "Animal.h"
#pragma once

class Turtle : public Animal
{
    public:
        Turtle(string name, int distanceToGoal);
        ~Turtle() = default;
        void run();
};

#endif // TURTLE_H