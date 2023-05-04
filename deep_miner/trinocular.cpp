#include "trinocular.h"

// creates a new Descendron
Trinocular::Trinocular() {
    // cout << "\nIn Trinocular constructor...";
    position_array initial_position = {0, 0};
    this->position = initial_position;
    this->position_pointer = make_shared<position_array>(initial_position);
    // cout << "\n Current position with shared pointer: x = " << (*position_pointer)[0] << " , y = " << (*position_pointer)[1] << "\n";
}


// Mines the value of its coordinates and the next two z-values, returns the gathered points
int Trinocular::mine(shared_ptr<field_vector> mine_field) {

    int points = 0;
    int number_mined_layers = 0;

    // check if field is empty (top element is 0)
    if (*((*mine_field).begin()) == 0) {
        cout << "\n!! This field is empty. There's nothing else to mine here.\n";
        return 0;
    }

    // iterate through field starting form the top
    for (auto field_layer = (*mine_field).begin(); field_layer != (*mine_field).end(); field_layer++) {

        // win points from this layer
        points = points + *field_layer;
        number_mined_layers++;

        // remove the mined layer from the field
        (*mine_field).erase((*mine_field).begin());

        // check if the robot already mined 3 layers, if so, exit loop
        if (number_mined_layers == 3) break;

        // check if the field is now empty, if so, add 0 to it to mark it as empty
        if ((*mine_field).empty()) {
            (*mine_field).push_back(0);
            cout << "\n!! Trinocular mined the rest of this field. The field is now empty.\n";
            break;
        }
    }
    cout << "\nTrinocular mined " << points << " points\n";
    return points;
}

// destroys this object
Trinocular::~Trinocular() {
    cout << "\nIn Trinocular destructor...";
}

// returns the shared pointer for this robot's current position
shared_ptr<position_array> Trinocular::get_position() {
    return this->position_pointer;
}

// prints this robot
void Trinocular::print_robot() {
    cout << "Trinocular\n";
}