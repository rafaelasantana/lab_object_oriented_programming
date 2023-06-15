#include "Animal.h"

// creates a new animal with a name and a distance to the goal
Animal::Animal(string name, bool distance) {
    this->name = name;
    this->distance_to_goal = distance;
    this->is_confused = false;
}

// an empty constructor for base classes
Animal::Animal(){}

// returns true if this animal's distance to the goal is less than 1
bool Animal::atGoal() {
    return this->distance_to_goal < 1 ? true : false;
}

// tricks the opponent with 1/6 chance
// throws an invalid argument Exception if the opponent is null
// throws an logic error Exception if the opponent is too far away (Distance > 5)
void Animal::trick(shared_ptr<Animal> opponent) {

}