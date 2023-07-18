#include "Turtle.h"

Turtle::Turtle(string name, int distanceToGoal) : Animal(name, distanceToGoal)
{
}

void Turtle::run()
{
    // check if turtle is confused
    if (this->isConfused) {
        // 2/3 chance of getting clear
        int clearChance = rand() % 3;
        // check if will got clear
        if (clearChance == 0 || clearChance == 1) {
            this->isConfused = false;
        }
    }
    // turtle is not confused
    else {
        // gets one unit closer to the goal
        this->distanceToGoal = distanceToGoal - 1;
    }
}
