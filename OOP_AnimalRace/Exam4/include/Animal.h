#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Animal
{
    public:
        Animal(string name, bool distance);
        Animal();
        virtual ~Animal();
        virtual void run();
        bool atGoal();
        void trick(shared_ptr<Animal> opponent);
    protected:
        string name;
        int distance_to_goal;
        bool is_confused;
};

#endif