#include "maxGrinder.h"

// creates a new MaxGrinder
MaxGrinder::MaxGrinder() {
}

// Mines the max value in this field and then sorts the field in
// ascending order.
int MaxGrinder::mine(shared_ptr<field_vector> mine_field) {
    // check if field is empty (top element is 0)
    if (field_is_empty_before_mining(mine_field)) return 0;
    mtx.lock();
    // get max value in this field
    auto max_iterator = max_element((*mine_field).begin(), (*mine_field).end());
    int max_value = *max_iterator;

    // remove max value from the field
    (*mine_field).erase(max_iterator);

    // check if the field is empty after mining
    if (!field_is_empty_after_mining(mine_field)) {
        // sort field values in ascending order
        sort((*mine_field).begin(), (*mine_field).end());
    }

    cout << "\nMaxGrinder mined " << max_value << " points\n";
    mtx.unlock();
    return max_value;
}

// returns true if there is nothing else to mine in this field
bool MaxGrinder::field_is_empty_before_mining(shared_ptr<field_vector> mine_field) {
    // check if field is empty (top element is 0)
    if (*((*mine_field).begin()) == 0) {
        cout << "\n!! This field is empty. There's nothing else to mine here.\n";
        return true;
    }
    return false;
}

// checks if the field is empty, if so, add 0 to it to mark it as empty
bool MaxGrinder::field_is_empty_after_mining(shared_ptr<field_vector> mine_field) {
    if ((*mine_field).empty()) {
        (*mine_field).push_back(0);
        cout << "\n!! MaxGrinder mined the rest of this field. The field is now empty.\n";
        return true;
    }
    return false;
}

// destroys this object
MaxGrinder::~MaxGrinder() {
    cout << "\nIn MaxGrinder destructor...";
}

// prints this robot
void MaxGrinder::print_robot() {
    cout << "MaxGrinder\n";
}