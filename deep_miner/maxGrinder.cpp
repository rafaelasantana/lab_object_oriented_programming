#include "maxGrinder.h"

// creates a new Descendron
MaxGrinder::MaxGrinder() {
    position_array initial_position = {0, 0};
    this->position = initial_position;
    this->position_pointer = make_shared<position_array>(initial_position);
}

// Mines the max value in this field and then sorts the field in
// ascending order.
int MaxGrinder::mine(shared_ptr<field_vector> mine_field) {

    // check if field is empty (top element is 0)
    if (*((*mine_field).begin()) == 0) {
        cout << "\n!! This field is empty. There's nothing else to mine here.\n";
        return 0;
    }

    // get max value in this field
    auto max_iterator = max_element((*mine_field).begin(), (*mine_field).end());
    int max_value = *max_iterator;

    // remove max value from the field
    (*mine_field).erase(max_iterator);

    // sort field values in ascending order
    sort((*mine_field).begin(), (*mine_field).end());

    cout << "\nMaxGrinder mined " << max_value << " points\n";
    return max_value;
}

// destroys this object
MaxGrinder::~MaxGrinder() {
    cout << "\nIn MaxGrinder destructor...";
}

// prints this robot
void MaxGrinder::print_robot() {
    cout << "MaxGrinder\n";
}