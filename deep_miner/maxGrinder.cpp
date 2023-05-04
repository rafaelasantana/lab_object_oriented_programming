#include "maxGrinder.h"

// creates a new Descendron
MaxGrinder::MaxGrinder() {
    // cout << "\nIn MaxGrinder constructor...";
    position_array initial_position = {0, 0};
    this->position = initial_position;
    this->position_pointer = make_shared<position_array>(initial_position);
}

// Finds the max and min values of its x- and y-coordinate.
// It grinds the max value and leaves the min value on the top of the field.
int MaxGrinder::mine(shared_ptr<field_vector> mine_field) {

    // check if field is empty (top element is 0)
    if (*((*mine_field).begin()) == 0) {
        cout << "\n!! This field is empty. There's nothing else to mine here.\n";
        return 0;
    }

    // get min and max values in this field
    auto minmax_result = minmax_element((*mine_field).begin(), (*mine_field).end());
    auto min_iterator = minmax_result.first;
    auto max_iterator = minmax_result.second;
    int min_value = *min_iterator;
    int max_value = *max_iterator;

    // remove max value from the field
    (*mine_field).erase(max_iterator);

    // remove min value from the field and put it back on the first position
    (*mine_field).erase(min_iterator);
    (*mine_field).insert((*mine_field).begin(), min_value);

    cout << "\nMaxGrinder mined " << max_value << " points\n";
    return max_value;
}

// destroys this object
MaxGrinder::~MaxGrinder() {
    cout << "\nIn MaxGrinder destructor...";
}

// returns the shared pointer for this robot's current position
shared_ptr<position_array> MaxGrinder::get_position() {
    return this->position_pointer;
}

// prints this robot
void MaxGrinder::print_robot() {
    cout << "MaxGrinder\n";
}