#include "Race.h"

Race::Race()
{
    //ctor
}

void Race::addAnimal(shared_ptr<Animal> animal)
{
    this->animals.push_back(animal);
}

// returns true if any animal reached the goal
bool Race::raceFinished()
{
    for (const auto &animal : animals)
    {
        if (animal->atGoal()) return true;
    }
    return false;
}

// prints the results for each animal in the race
void Race::printResult()
{
    cout << "\n*** RESULTS ***\n";
    for (const auto &animal : animals)
    {
        animal->printAnimal();
    }
    cout << "\n****************\n";
}

// each animal tries to trick another animal
void Race::trickEachother()
{
    for (const auto &trickerAnimal : animals){
        cout << "\nTricker:\n";
        trickerAnimal->printAnimal();
        // choose a random animal to trick
        int randomIndex =  rand() % animals.size();
        shared_ptr<Animal> randomAnimal = animals[randomIndex];
        // check if the randomAnimal is not the same as the trickerAnimal
        if (randomAnimal == trickerAnimal) {
            // try to get the animal before
            if (randomIndex > 0) {
                randomAnimal = animals[randomIndex - 1];
            }
            // or get the next animal
            else {
                randomAnimal = animals[randomIndex + 1];
            }
        }
        cout << "\nVictim:\n";
        randomAnimal->printAnimal();
        // trick randomAnimal
        trickerAnimal->trick(randomAnimal);
    }
}

void Race::competition()
{
    //Racing loop
    while(!raceFinished())
    {
        cout << "\n* Race turn *\n";

        for (const auto& animal: animals) {
            cout << "\nAnimal " << animal->name << " will run\n";
            animal->run();
            animal->printAnimal();
        }

        // try catch block
        try {
            trickEachother();
        }
        catch(const invalid_argument& e) {
            cout << "\n!!  Invalid argument exception: " << e.what() << endl;
        }
        catch (const logic_error& e) {
            cout << "\n!! Logic error exception: " << e.what() << endl;
        }
    }

    printResult();
}