#include "trinocular.h"

// creates a new Trinocular
Trinocular::Trinocular() {
}

// Mines the value of its coordinates and the next two z-values, returns the gathered points
int Trinocular::mine(shared_ptr<field_vector> mine_field) {

    int points = 0;
    int number_mined_layers = 0;

    // check if field is empty before mining
    if (field_is_empty_before_mining(mine_field)) return 0;

    // iterate through field starting form the top
    for (int field_layer = 0; field_layer < 3; field_layer++) {

        // win points from this layer
        if(!(*mine_field).empty()) {
            points = points + *(*mine_field).begin();
            (*mine_field).erase((*mine_field).begin());
        }
        // number_mined_layers++;

        // // check if the robot already mined 3 layers, if so, exit loop
        // if (number_mined_layers == 3) break;

        // check if the field is empty after mining, if so, mark it as empty and break loop
    }
    field_is_empty_after_mining(mine_field);
    cout << "\nTrinocular mined " << points << " points\n";
    mtx.unlock();
    return points;
}

// returns true if there is nothing else to mine in this field
bool Trinocular::field_is_empty_before_mining(shared_ptr<field_vector> mine_field) {
    // check if field is empty (top element is 0)
    if (*((*mine_field).begin()) == 0) {
        cout << "\n!! This field is empty. There's nothing else to mine here.\n";
        return true;
    }
    return false;
}

// checks if the field is empty, if so, add 0 to it to mark it as empty
bool Trinocular::field_is_empty_after_mining(shared_ptr<field_vector> mine_field) {
    if ((*mine_field).empty()) {
        (*mine_field).push_back(0);
        cout << "\n!! Trinocular mined the rest of this field. The field is now empty.\n";
        return true;
    }
    return false;
}

// destroys this object
Trinocular::~Trinocular() {
    cout << "\nIn Trinocular destructor...";
}

// prints this robot
void Trinocular::print_robot() {
    cout << "Trinocular\n";
}