// implements the class Fighter
#include "Fighter.h"
#include <iostream>
using namespace std;

int x, y, x_max, y_max;
Skill* skills;

// creates a new fighter and sets it in a random starting position
Fighter::Fighter(int world_dimension) {
    this->world_dimension = world_dimension;
    this->x_max = world_dimension - 1;
    this->y_max = world_dimension - 1;
    int* starting_point = get_random_position();
    this->x = starting_point[0];
    this->y = starting_point[1];
    delete starting_point;
}

// moves the fighter in a given direction
void Fighter::move(char direction) {

    switch (direction)
        {
        case 'w': // up
            if (this->y < y_max) {
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
        return;
}

// moves a fighter in any direction (used to move enemies)
void Fighter::move() {
    bool is_legal_move = false;
    while (!is_legal_move) {
        int dir = rand() % world_dimension;
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

// returns a random position in the field
int* Fighter::get_random_position() {
    int random_x = rand() % this->world_dimension;
    int random_y = rand() % this->world_dimension;

    int* position = new int[2];
    position[0] = random_x;
    position[1] = random_y;
    return position;
}

// returns the current x and y coordinates for this fighter
int* Fighter::get_position() {
    int* position = new int[2];
    position[0] = this->x;
    position[1] = this->y;
    return position;
}

Fighter::~Fighter() {
    // delete skills;
    // TODO: not working, why?
    //delete position;
};
//TODO
int Fighter::fight(const Fighter& other) {
    return 0;
};

void Fighter::print_error_field_limit() {
cout << "You have reached the field limit! Try going in another direction" << endl;
}

// prints an enemy (virtual, if it's a character, will execute the function in character)
void Fighter::print() {
    cout << "____________________" << endl;
    cout << "________ENEMY_______" << endl;
    cout << "Position [ " << this->x << " , " << this->y << " ]" << endl;
    cout << "____________________" << endl;
}

