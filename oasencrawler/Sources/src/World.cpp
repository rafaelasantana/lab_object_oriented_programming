// implements the class World
#include <iostream>
#include "World.h"
//#include "Character.cpp"
using namespace std;

// constructor
World::World(int dimension) {

    // create two-dimensional array with dimension x dimension
    this->dimension = dimension;
    this->fields = new int*[dimension];
    this->relics = 0;
    for(int i = 0; i < dimension; i++) {
        fields[i] = new int[dimension];
    }

    // TODO: make sure there is at least one relic!
    // fill array with field types
    for(int i = 0; i < dimension; i++) {
        int* row = fields[i];

        for(int j = 0; j < dimension; j++) {
            int field_value = generate_random_field();
            row[j] = field_value;
        }
    }
};

// generates a random field of Empty, Danger, Well or Relics
int World::generate_random_field() {
    int random = rand() % 10; // random int from 0-9
    int field_value;
    if (random >= 0 && random < 4) {
        field_value = 0; // empty field with probability 4/10
    }
    else if (random >= 4 && random < 8) {
        field_value = 1; // danger field with probability 4/10
    }
    else if (random == 8) {
        field_value = 2; // well field with probability 1/10
    }
    else {
        field_value = 3; // relics field with probability 1/10
        this->relics = relics + 1;
    }
    return field_value;
}

// prints the world fields
void World::print_world() {

    int** fields = this->fields;
    int dimension = this->dimension;

    for (int i = 0; i < dimension; i++) {
        int* row = fields[i];

        for(int j = 0; j < dimension; j++) {
            int value = row[j];
            cout << "position [" << i << ", " << j << "] value: " << value << endl;
        }
    }
}

// uncovers the field reached by the character, applies consequences to character and marks the field as empty
void World::uncover_field(Character* c) {
    int* position = c->get_position();
    int x = position[0];
    int y = position[1];
    int field = fields[x][y];

    switch (field) {
    case 0: { // empty field -> nothing happens
        cout << "You reached an empty field." << endl;
        break;
    }
    case 1: { // danger field -> the character gets hurt with probability 1/6
        int danger = rand() % 6;
        if (danger == 0) {
            cout << "You reached a dangerous field and got hurt! You lose 1 life point." << endl;
            c->lose_life();
            clear_field(x, y);
        }
        else {
            cout << "You reached a dangerous field, but were not attacked." << endl;
            clear_field(x, y);
        }
        break;
    }
    case 2: { // well field -> character wins a life point
        cout << "You reached a well and got an extra life!" << endl;
        c->win_life();
        clear_field(x, y);
        break;
    }
    case 3: { // relics field -> character wins a relic
        cout << "You found a relic!" << endl;
        c->win_relic();
        clear_field(x, y);
        break;
    }
    default:
        break;
    }
}

// marks an uncovered field as empty
void World::clear_field(int x, int y) {
    this->fields[x][y] = 0;
};


// checks on the character's life points and relics points
void World::check_character(Character* c) {
    if (c->is_alive()) {
        if (c->get_relics_points() == relics) {
            cout << "You have found all the relics in this world! You WIN!" << endl;
        }
    }
    else {
        cout << "You DIE :(" << endl;
    }
}