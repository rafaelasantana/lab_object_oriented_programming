#include "Animal.h"

Animal::Animal(string name, int distanceToGoal)
{
    this->name = name;
    this->distanceToGoal = distanceToGoal;
    this->isConfused  = false;
}

// returns true if the distance to goal is less than 1
bool Animal::atGoal()
{
    return this->distanceToGoal < 1 ? true : false;
}

void Animal::trick(shared_ptr<Animal> otherAnimal)
{
    // check if otherAnimal is a valid pointer
    if (otherAnimal ==  nullptr) {
        throw invalid_argument("Opponent NULL");
    }

    // check if otherAnimal is too far away
    int distanceDifference = abs(this->distanceToGoal - otherAnimal->distanceToGoal);
    if (distanceDifference > 5) throw logic_error("Opponent too far away");

    // trick the otherAnimal with a 1/6 chance
    int chance = rand() % 6;
    // if chance = 5 (1/6 chance), otherAnimal gets confused
    if (chance == 5) {
        otherAnimal->isConfused = true;
        cout << "\n!! The " << otherAnimal->name << " got distracted!\n";
    }
}

void Animal::printAnimal()
{
    cout << "\n[ Name: " << this->name << " | Distance to goal: " << this->distanceToGoal << " ]\n";
}
