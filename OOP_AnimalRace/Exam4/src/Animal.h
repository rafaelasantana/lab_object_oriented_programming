
#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <memory>
#include <stdexcept>

#pragma once

using namespace std;
class Animal
{
    public:
        Animal(string name, int distanceToGoal);
        virtual ~Animal() = default;
        virtual void run() = 0;
        virtual bool atGoal();
        virtual void trick(shared_ptr<Animal> otherAnimal);
        virtual void printAnimal();
        string name;
        int distanceToGoal;
        bool isConfused;
};

#endif // ANIMAL_H
