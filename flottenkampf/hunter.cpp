#include "hunter.h"
#include "ship.cpp"

// creates a new Hunter and sets hull, size and damage values
Hunter::Hunter() {
    this->hull = 75;
    this->size = 4;
    this->damage = 30;
    cout << "\nCreated Hunter...\n";
}

Hunter::~Hunter() {
    cout << "\nDestroying Hunter...\n";
}

void Hunter::print_ship() {
    cout << "\n** Hunter **\n";
    cout << "\n  Hull: " << this->hull;
    cout << "\n  Size: " << this->size;
    cout << "\n  Damage: " << this->damage;
    cout << "\n**************\n";
}

int Hunter::get_size()
{
    return Ship::get_size();
}

int Hunter::get_hull()
{
    return Ship::get_hull();
}

int Hunter::get_damage()
{
    return Ship::get_damage();
}

void Hunter::suffer_attack()
{
    Ship::suffer_attack();
}

bool Hunter::is_destroyed()
{
    return Ship::is_destroyed();
}

// attacks the opponent's ship
void Hunter::attack_ship(shared_ptr<Ship> opponents_ship, shared_ptr<Fleet> opponents_fleet)
{
    // throw 10 sided dice for the attack
    int dice_result = rand() % 10;
    // execute attack
    bool is_success = dice_result >= opponents_ship->get_size();

    // check if attack was successful
    if (is_success)
    {
        cout << "\nThe attack was successful!\n";
        // attack opponent's ship
        opponents_ship->suffer_attack();
        // check if dice result qualifies for an extra attack
        if (dice_result >= 9) opponents_ship->suffer_attack();
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

void Hunter::use_special_power() {
    cout << "\nUsing special power for Hunter...\n";
}