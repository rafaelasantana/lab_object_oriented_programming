#ifndef RABBIT_H
#define RABBIT_H
#include "Animal.h"

class Rabbit : public Animal
{
    public:
        Rabbit(string name, bool distance);
        ~Rabbit();
        void run();
    private:
        bool is_asleep;

};

#endif