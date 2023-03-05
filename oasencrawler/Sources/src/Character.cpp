// implements the class Character
#include "Character.h"
#include <iostream>
using namespace std;

void print_error_field_limit();

// constructor
Character::Character(int world_dimension) {
    this->life_points = 5;
    this->relics_points = 0;
    this->x = 0;
    this->y = 0;
    this->x_max = world_dimension - 1;
    this->y_max = world_dimension - 1;
}

// moves the character in a given direction
void Character::move(char direction) {
    switch (direction)
    {
    case 'w': // up
        if (y < y_max) {
            this->y = y + 1;
        }
        else print_error_field_limit();
        break;
    case 's': // down
        if (y > 0) this->y = y - 1;
        else print_error_field_limit();
        break;
    case 'a': // left
        if (x > 0) this->x = x - 1;
        else print_error_field_limit();
        break;
    case 'd': // right
        if (x < x_max){
            this->x = x + 1;
        }
        else print_error_field_limit();
        break;
    default:
        break;
    }
    print_character();
    return;
}

// returns the current x and y coordinates for this character
int* Character::get_position() {
    int* position = new int[2];
    position[0] = this->x;
    position[1] = this->y;
    return position;
}

// character loses a life point
void Character::lose_life() {
    this->life_points = life_points - 1;
};

// character wins a life point
void Character::win_life() {
    cout << "before winning a life = " << this->life_points << endl;
    this->life_points = this->life_points + 1;
    cout << "after winning a life = " << this->life_points << endl;
};

// character wins a relic
void Character::win_relic() {
    cout << "before winning a relic = " << this->relics_points << endl;
    this->relics_points = this->relics_points + 1;
    cout << "after winning a relic = " << this->relics_points << endl;
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
void Character::print_character() {
    cout << "____________________" << endl;
    cout << "Life points: " << this->life_points << endl;
    cout << "Relics points: " << this->relics_points << endl;
    cout << "Position [ " << this->x << " , " << this->y << " ]" << endl;
    cout << "____________________" << endl;
}


void print_error_field_limit() {
    cout << "You have reached the field limit! Try going in another direction" << endl;
}

