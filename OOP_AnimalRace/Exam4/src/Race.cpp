#include "Race.h"

Race::Race()
{
    //ctor
}

Race::~Race()
{
    //dtor
}

void Race::competition()
{
    //Racing loop
    while(!raceFinished())
    {

        for(Animal* tmpAnimal: animals)
        {
            tmpAnimal->run();
        }

        // try catch block
        trickEachother();
    }

    printResult();
}
