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

// creates a new enemy is is_enemy is set to true, otherwise does nothing
Character::Character(int world_dimension, bool is_enemy) {
    if (is_enemy) {
        this->life_points = 5;
        this->relics_points = 0;
        this->x_max = world_dimension - 1;
        this->y_max = world_dimension - 1;
        this->x = x_max;
        this->y = y_max;
    }
}

// moves an enemy character in a random direction
void Character::move_enemy() {

    bool is_legal_move = false;
    while (!is_legal_move) {
        int dir = rand() % 4;
        switch (dir) {
            case 0: { // up
                if (this->y < y_max) {
                    this->y = y + 1;
                    is_legal_move = true;
                }
                break;
            }
            case 1: { // down
                if (this->y > 0) {
                    this->y = y - 1;
                    is_legal_move = true;
                }
                break;
            }
            case 2: { // left
                if (this->x > 0) {
                    this->x = x - 1;
                    is_legal_move = true;
                }
                break;
            }
            case 3: { // right
                if (this->x < x_max) {
                    this->x = x + 1;
                    is_legal_move = true;
                }
                break;
            }
            default:
                break;
        }
    }
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
void Character::print_character() {

    cout << "____________________" << endl;
    cout << "_______PLAYER_______" << endl;
    cout << "Life points: " << this->get_life_points() << endl;
    cout << "Relics points: " << this->get_relics_points() << endl;
    cout << "Position [ " << this->x << " , " << this->y << " ]" << endl;
    cout << "____________________" << endl;
}

// prints the enemy's position
void Character::print_enemy() {
    cout << "____________________" << endl;
    cout << "________ENEMY_______" << endl;
    cout << "Position [ " << this->x << " , " << this->y << " ]" << endl;
    cout << "____________________" << endl;
}

// kills the character
void Character::kill_character() {
    this->life_points = 0;
}

void print_error_field_limit() {
    cout << "You have reached the field limit! Try going in another direction" << endl;
}

