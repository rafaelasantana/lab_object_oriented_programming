// implements the class Character
#include "Character.h"
#include <iostream>
using namespace std;

// defining default constructor
Character::Character(){}

// creates a new Character and sets it in a random position
Character::Character(int world_dimension) : Fighter(world_dimension)
{
    this->life_points = 5;
    this->relics_points = 0;
}

// moves the character in a given direction
void Character::move(char direction) {
    Fighter::move(direction);
    print();
    return;
}

// character loses a life point
void Character::lose_life() {
    this->life_points = life_points - 1;
};

// character wins a life point
void Character::win_life() {
    this->life_points = this->life_points + 1;
};

// character wins a relic
void Character::win_relic() {
    this->relics_points = this->relics_points + 1;
};

// returns the current life points
int Character::get_life_points() {
    return this->life_points;
};

// returns the current relics points
int Character::get_relics_points() {
    return this->relics_points;
};

// checks if the character has at least 1 life point
bool Character::is_alive() {
    return (this->life_points > 0) ? true : false;
};

// prints the character's position, life- and relics-points
void Character::print() {

    int* curr_position = Fighter::get_position();

    cout << "____________________" << endl;
    cout << "_______PLAYER_______" << endl;
    cout << "Life points: " << this->get_life_points() << endl;
    cout << "Relics points: " << this->get_relics_points() << endl;
    cout << "Position [ " << curr_position[0] << " , " << curr_position[1] << " ]" << endl;
    cout << "____________________" << endl;

    delete curr_position;
}

// kills the character
void Character::kill_character() {
    this->life_points = 0;
}

Character::~Character() {
    // delete skills;
}

