#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Race.cpp"
#include "Rabbit.cpp"
#include "Turtle.cpp"
#include "Animal.cpp"

using namespace std;

int main()
{
    //Seeding random number generator
    srand(time(nullptr));

    // creating the game
    Race wineyard;

    //creating starters
    shared_ptr<Animal> roger = make_shared<Rabbit>("Roger", 20);
    shared_ptr<Animal> bugs = make_shared<Rabbit>("Bugs", 20);
    shared_ptr<Animal> donatello = make_shared<Turtle>("Donatello", 20);
    shared_ptr<Animal> raphael = make_shared<Turtle>("Raphael", 20);

    // adding animals to the race
    wineyard.addAnimal(roger);
    wineyard.addAnimal(bugs);
    wineyard.addAnimal(donatello);
    wineyard.addAnimal(raphael);

    // run the game
    wineyard.competition();

    return 0;
}
