#include "ship.h"

int Ship::get_size()
{
    return this->size;
}

int Ship::get_hull()
{
    return this->hull;
}

int Ship::get_damage()
{
    return this->damage;
}

// subtracts this ship's damage value from this ship's hull value
// if the hull value falls under 1, this ship is destroyed
void Ship::suffer_attack()
{
    this->hull = hull - this->damage;
}

// returns true if the hull value is under 1
bool Ship::is_destroyed()
{
    return this->hull < 1 ? true : false;
}
