#ifndef RABBIT_H
#define RABBIT_H
#include "Animal.h"
#pragma once

class Rabbit : public Animal
{
    public:
        Rabbit(string name, int distanceToGoal);
        ~Rabbit() = default;
        void run();
        bool isAsleep;
};

#endif // RABBIT_H