// implements the class World
#include <iostream>
#include "World.h"
using namespace std;

// constructor
World::World(int dimension) {
    this->difficulty_level = 0;
    this->relics = 0;

    // create empty two-dimensional array with dimension x dimension
    this->dimension = dimension;
    this->fields = new int*[dimension];

    for(int i = 0; i < dimension; i++) {
        fields[i] = new int[dimension];
    }

    // fill the world with random fields
    fill_world(difficulty_level);
};

// fills the world with random fields (and with at least one relic)
// the bigger the difficulty, the more enemies
void World::fill_world(int difficulty) {
    int relic_counter = 0;

    // fill array with field types
    for(int i = 0; i < dimension; i++) {
        int* row = this->fields[i];

        for(int j = 0; j < dimension; j++) {
            int field_value = generate_random_field(difficulty);
            // check if a relic was added
            if (field_value == 3) {
                relic_counter++;
            }
            // hard insert a relic in case there is none yet
            if (i == dimension - 1 && j == dimension - 1 && relic_counter == 0) {
                field_value = 3;
            }
            row[j] = field_value;
        }
    }

}

// generates a random field of Empty, Danger, Well or Relics
int World::generate_random_field(int difficulty) {
    int random = rand() % 10; // random int from 0-9
    int field_value;
    if (random >= 0 && random < (4 - difficulty)) {
        field_value = 0; // empty field with probability 4/10
    }
    else if (random >= (4 - difficulty) && random < 8) {
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

// creates a new character
void World::add_character() {
    Character* c = new Character(this->dimension);
    this->player = c;
}

// adds a new enemy
void World::add_enemy() {
    this->enemy = new Fighter(this->dimension);
    // Character* enemy = new Character(this->dimension, true);
    // this->enemy = enemy;
}

// moves the enemy in a random direction, checks if it has found the player and prints the enemy's position
void World::move_enemy() {
    // this->enemy->move_enemy();
    this->enemy->move();
    int* enemy_pos = this->enemy->get_position();
    int* character_pos = this->player->get_position();
    bool comp_x = enemy_pos[0] == character_pos[0];
    bool comp_y = enemy_pos[1] == character_pos[1];

    // kill character if the enemy has found it
    if (comp_x && comp_y) {
        kill_player();
        cout << "*** The enemy has found you! You LOSE! ***" << endl;
    }
    // print position
    this->enemy->print();
}

// kills the character
void World::kill_player() {
    this->player->kill_character();
}

// moves the player to the new field, uncovers the field and checks on the character's status. Then, moves the enemy
void World::move_character(char direction) {
    this->player->move(direction);
    // uncover the field reached by the character
    uncover_field(this->player);
    // checks on the character's life points and relics
    check_character(this->player);
    // move enemy
    move_enemy();
}

// returns if the player is alive
bool World::character_is_alive() {
    return this->player->is_alive();
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
    delete[]position;
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
            //clear_field(x, y);
        }
        else {
            cout << "You reached a dangerous field, but were not attacked." << endl;
            //clear_field(x, y);
        }
        break;
    }
    case 2: { // well field -> character wins a life point
        cout << "You reached a well and got an extra life!" << endl;
        c->win_life();
        //clear_field(x, y);
        break;
    }
    case 3: { // relics field -> character wins a relic
        cout << "You found a relic!" << endl;
        c->win_relic();
        //clear_field(x, y);
        break;
    }
    default:
        break;
    }
    clear_field(x, y);
}

// marks an uncovered field as empty
void World::clear_field(int x, int y) {
    this->fields[x][y] = 0;
};

// checks on the character's life points and relics points. If it has found all relics,
// fill the world again with new fields an a higher difficulty level
void World::check_character(Character* c) {
    if (c->is_alive()) {
        if (c->get_relics_points() == relics) {
            cout << "*** You have found all the relics in this world!! ***" << endl;
            cout << "Welcome to the next level!" << endl;
            this->difficulty_level = difficulty_level + 1;
            fill_world(this->difficulty_level);
        }
    }
    else {
        cout << "*** You LOSE ***" << endl;
    }
}

World::~World() {
    delete fields;
    delete player;
    delete enemy;
}