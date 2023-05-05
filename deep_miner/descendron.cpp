#include "descendron.h"

// creates a new Descendron
Descendron::Descendron() {
    // cout << "\nIn Descendron constructor...";
    position_array initial_position = {0, 0};
    this->position = initial_position;
    this->position_pointer = make_shared<position_array>(initial_position);
    // cout << "\n Current position with shared pointer: x = " << (*position_pointer)[0] << " , y = " << (*position_pointer)[1] << "\n";
}

// Sorts all z-values of its current x- and y-coordinate
// in descending order and then mines the highest value of the order.
// Returns the max value in this field
int Descendron::mine(shared_ptr<field_vector> mine_field) {
    cout << "\nDescendron is mining...";

    // check if field is empty (top element is 0)
    if (*((*mine_field).begin()) == 0) {
        cout << "\n!! This field is empty. There's nothing else to mine here.\n";
        return 0;
    }

    // sort field values in descending order
    sort((*mine_field).begin(), (*mine_field).end(), greater<int>());

    // get max value in this field
    auto max_iterator = max_element((*mine_field).begin(), (*mine_field).end());
    int max_value = *max_iterator;

    // remove max value from this field
    (*mine_field).erase(max_iterator);

    cout << "\nDescendron mined " << max_value << " points\n";
    return max_value;
}

// destroys this object
Descendron::~Descendron() {
    cout << "\nIn Descendron destructor...";
}

// prints this robot
void Descendron::print_robot() {
    cout << "Descendron\n";
}
