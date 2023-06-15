#include "fleet.h"

// creates a Fleet
Fleet::Fleet(string name)
{
    this->name = name;
    cout << "\nCreated Fleet\n";
}

// destroys this Fleet
Fleet::~Fleet()
{
    cout << "\nDestroying Fleet...\n";
}

// adds a new ship to this Fleet
void Fleet::add_ship(shared_ptr<Ship> ship)
{
    this->ships.push_back(ship);
}

// prints all ships in this Fleet
void Fleet::print_fleet()
{
    cout << "\n====== Fleet " << this->name << " ======\n";

    for (const auto &ship : ships)
    {
        ship->print_ship();
    }

    cout << "\n=======================\n";
}

// returns the amount of ships in this fleet
int Fleet::get_fleet_size()
{
    return this->ships.size();
}

// sets the opponent Fleet
void Fleet::set_opponent(shared_ptr<Fleet> opponent)
{
    this->opponent = opponent;
}

// this fleet plays alternating battle turns with the opponent
// a ship from this fleet attacks a ship from the opponent's fleet
void Fleet::play_turn()
{
    // choose ship from this fleet
    shared_ptr<Ship> this_ship = this->get_random_ship();
    // choose target ship from opponent's fleet
    shared_ptr<Ship> opponents_ship = this->opponent->get_random_ship();

    // check if this fleet is empty
    if (this_ship == nullptr)
    {
        // print opponent's victory
        cout << "\nThe " << this->name << " Fleet is empty, " << this->opponent->get_name() << " Fleet wins!\n";
        return;
    }
    // check if the opponent's fleet is empty
    if (opponents_ship == nullptr)
    {
        // print this fleet's victory
        cout << "\nThe " << this->opponent->get_name() << " Fleet is empty, " << this->name << " Fleet wins!\n";
        return;
    }

    // print attacking ship
    cout << "\nAttacking ship from " << this->name << "\n";
    this_ship->print_ship();
    // print target ship
    cout << "\nTarget ship from " << this->opponent->get_name() << "\n";
    opponents_ship->print_ship();

    // attack opponent's ship
    this_ship->attack_ship(opponents_ship, this->opponent);

    // opponent plays the next turn
    this->opponent->play_turn();
}

// returns a random ship from this fleet
// or the nullptr if the fleet is empty
shared_ptr<Ship> Fleet::get_random_ship()
{
    // get this fleet's size
    int size = this->get_fleet_size();

    // if the fleet is empty, return the null pointer
    if (size < 1)
    {
        return nullptr;
    }
    // generate a random index of the ships vector
    int random_index = rand() % size;
    // get the ship at the random index
    shared_ptr<Ship> random_ship = this->ships[random_index];
    // return the random ship
    return random_ship;
}

// removes the ship from this fleet
void Fleet::lose_ship(shared_ptr<Ship> ship)
{
    this->ships.erase(remove(ships.begin(), ships.end(), ship), ships.end());
}

// returns the name of this fleet
string Fleet::get_name()
{
    return this->name;
}

