#ifndef RACE_H
#define RACE_H
#include "Animal.h"
#include <vector>

class Race
{
    public:
        Race();
        ~Race() = default;
        void addAnimal(shared_ptr<Animal> animal);
        bool raceFinished();
        void printResult();
        void trickEachother();
        void competition();

        vector<shared_ptr<Animal> > animals;

};

#endif // RACE_H
