// implements the class Fighter
#include "Fighter.h"
#include <iostream>
#include <list>
using namespace std;

list<Skill> skills;

// defining default constructor
Fighter::Fighter(){
}

// creates a Fighter with a name (used for BeatEmUp)
Fighter::Fighter(string name){
    this->name = name;
    this->life_points = 5;
    this->victories = 0;
    this->defeats = 0;
}

// creates a new fighter and sets it in a random starting position
Fighter::Fighter(int world_dimension) {
    this->world_dimension = world_dimension;
    this->x_max = world_dimension - 1;
    this->y_max = world_dimension - 1;

    int* starting_point = get_random_position();
    this->x = starting_point[0];
    this->y = starting_point[1];
    this->life_points = 5;
    delete starting_point;
}

// adds skill to the skills list
void Fighter::add_skill(Skill skill) {
    this->skills.push_front(skill);
}

// returns the skills list
list<Skill> Fighter::get_skills() {
    return this->skills;
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

// deletes heap allocated items
Fighter::~Fighter() {
};

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

// prints a fighter (BeatEmUp game)
void Fighter::print_fighter() {
    Skill first_skill = get_skill(0);
    Skill second_skill = get_skill(1);

    // cout << "__________________________________________" << endl;
    cout << "____________________"<< this->name << "____________________" << endl;
    first_skill.print();
    second_skill.print();
    cout << "Life points: " << this->life_points << endl;
    cout << "Victories: " << this->victories << endl;
    cout << "Defeats: " << this->defeats << endl;
    cout << "____________________________________________" << endl;
}

// get's this character's skill
Skill Fighter::get_skill(int index) {
    list<Skill>::iterator it = skills.begin();
    for(int i=0; i < skills.size(); i++) {
        if (i == index) return *it;
        ++it;
    }
    return Skill("null skill, check your code!!", 0, 0);
}

// adds one victory to fighter
void Fighter::add_victory() {
    this->victories = victories + 1;
}
// adds one defeat to fighter
void Fighter::add_defeat() {
    this->defeats = defeats + 1;
}

// fighter loses a life
void Fighter::lose_life() {
    this->life_points = life_points - 1;
}

// returns 1 if the fighter has at least one life point
bool Fighter::is_alive() {
    return (this->life_points > 0) ? true : false;
}

// returns a random skill for this fighter
Skill Fighter::get_random_skill() {
    int random_index = rand() % skills.size();
    return get_skill(random_index);
}

// returns this fighter's name
string Fighter::get_name() {
    return this->name;
}

// restores the life points for this fighter
void Fighter::restore_life_points() {
    this->life_points = 5;
}

