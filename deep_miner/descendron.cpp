#include "descendron.h"

// creates a new Descendron
Descendron::Descendron() {
    // cout << "\nIn Descendron constructor...";
    position_array initial_position = {0, 0};
    this->position = initial_position;
    this->position_pointer = make_shared<position_array>(initial_position);
    // cout << "\n Current position with shared pointer: x = " << (*position_pointer)[0] << " , y = " << (*position_pointer)[1] << "\n";
}

// digs the
int Descendron::mine(shared_ptr<field_vector> mine_field) {
    return 0;
}

// destroys this object
Descendron::~Descendron() {
    cout << "\nIn Descendron destructor...";
}

// returns the shared pointer for this robot's current position
shared_ptr<position_array> Descendron::get_position() {
    return this->position_pointer;
}

// prints this robot
void Descendron::print_robot() {
    cout << "Descendron\n";
}
