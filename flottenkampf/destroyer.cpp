#include "destroyer.h"

// creates a new Destroyer and sets hull, size and damage values
Destroyer::Destroyer() {
    this->hull = 150;
    this->size = 6;
    this->damage = 60;
    cout << "\nCreated Destroyer...\n";
}

Destroyer::~Destroyer() {
    cout << "\nDestroying Destroyer...\n";
}

void Destroyer::print_ship() {
    cout << "\n** Destroyer **\n";
    cout << "\n  Hull: " << this->hull;
    cout << "\n  Size: " << this->size;
    cout << "\n  Damage: " << this->damage;
    cout << "\n**************\n";
}

int Destroyer::get_size()
{
    return Ship::get_size();
}

int Destroyer::get_hull()
{
    return Ship::get_hull();
}

int Destroyer::get_damage()
{
    return Ship::get_damage();
}

void Destroyer::suffer_attack()
{
    Ship::suffer_attack();
}

bool Destroyer::is_destroyed()
{
    return Ship::is_destroyed();
}

// attacks the opponent's ship
void Destroyer::attack_ship(shared_ptr<Ship> opponents_ship, shared_ptr<Fleet> opponents_fleet)
{
    // throw 10 sided dice for the attack
    int dice_result = rand() % 10;
    // execute attack with special power -> targeting: Hit checks are lightened by 2.
    bool is_success = dice_result >= (opponents_ship->get_size() - 2);

    // check if attack was successful
    if (is_success)
    {
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
    }
    else
    {
        // this attack is over
        cout << "\nThe attack failed\n";
    }
}

void Destroyer::use_special_power() {
    cout << "\nUsing special power for Destroyer...\n";
}