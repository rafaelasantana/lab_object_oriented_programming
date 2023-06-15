#include "cruiser.h"

// creates a new Cruiser and sets hull, size and damage values
Cruiser::Cruiser() {
    this->hull = 250;
    this->size = 8;
    this->damage = 50;
    cout << "\nCreated Cruiser...\n";
}

// destroys this cruiser
Cruiser::~Cruiser() {
    cout << "\nDestroying Cruiser...\n";
}

void Cruiser::print_ship() {
    cout << "\n** Cruiser **\n";
    cout << "\n  Hull: " << this->hull;
    cout << "\n  Size: " << this->size;
    cout << "\n  Damage: " << this->damage;
    cout << "\n**************\n";
}

int Cruiser::get_size()
{
    return Ship::get_size();
}

int Cruiser::get_hull()
{
    return Ship::get_hull();
}

int Cruiser::get_damage()
{
    return Ship::get_damage();
}

void Cruiser::suffer_attack()
{
    Ship::suffer_attack();
}

bool Cruiser::is_destroyed()
{
    return Ship::is_destroyed();
}

// attacks the opponent's ship
void Cruiser::attack_ship(shared_ptr<Ship> opponents_ship, shared_ptr<Fleet> opponents_fleet)
{
    // throw 10 sided dice for the attack
    int dice_result = rand() % 10;
    // execute attack
    bool is_success = dice_result >= opponents_ship->get_size();

    // check if attack was successful
    if (is_success)
    {
        // check if opponent's ship was sunk during the previous attack (due to special power)
        if (opponents_ship->is_destroyed()) return;

        // print success message
        cout << "\nThe attack was successful!\n";
        // attack opponent's ship
        opponents_ship->suffer_attack();
        // print opponent's ship after the attack
        cout << "\nTarget ship after attack:\n";
        opponents_ship->print_ship();
        // check if ship sunk after the attack
        if (opponents_ship->is_destroyed())
        {
            // remove ship from opponent's fleet
            opponents_fleet->lose_ship(opponents_ship);
            cout << "\nThe opponent's ship sunk!\n";
        }
        // use special power-> bombardment: Cruisers may perform another attack if the first one was successful.
        attack_ship(opponents_ship, opponents_fleet);
    }
    else
    {
        // this attack is over
        cout << "\nThe attack failed\n";
    }
}

void Cruiser::use_special_power() {
    cout << "\nUsing special power for Cruise...\n";
}

