#include "Rabbit.h"

Rabbit::Rabbit(string name, int distanceToGoal) : Animal(name, distanceToGoal)
{
    this->isAsleep = false;
};

void Rabbit::run()
{
    // check if Rabbit is confused
    if (this->isConfused) {
        // 1/3 chance to get clear again
        int chanceToGetClear = rand() % 3;
        // check if got clear
        if (chanceToGetClear == 1) {
            this->isConfused = false;
        }
    }
    // check if Rabbit is awake
    else if (!this->isAsleep)
    {
        // get 3 units closer to the goal
        this->distanceToGoal = distanceToGoal - 3;

        // check if did not reach goal yet
        if (!this->atGoal())
        {
            // 1/3 chances to sleep
            int chanceToSleep = rand() % 3;
            // check if will sleep
            if (chanceToSleep == 2)
            {
                this->isAsleep = true;
                cout << "\nThe " << this->name << " Rabbit fell asleep at " << this->distanceToGoal << " from the goal\n";
            }
        }
    }
    // rabbit is asleep
    else {
        // 1/3 of waking up
        int chanceToWakeUp = rand() % 3;
        // check if woke up
        if (chanceToWakeUp == 0) {
            this->isAsleep = false;
        }
    }
}