#include "descendron.h"

// creates a new Descendron
Descendron::Descendron() {
}

// Sorts all z-values of its current x- and y-coordinate
// in descending order and then mines the highest value of the order.
// Returns the max value in this field
int Descendron::mine(shared_ptr<field_vector> mine_field) {
    // check if field is empty before mining, if so, no points are mined
    if (field_is_empty_before_mining(mine_field)) return 0;
    mtx.lock();

    // sort field values in descending order
    sort((*mine_field).begin(), (*mine_field).end(), greater<int>());
    // get max value in this field
    // auto max_iterator = max_element((*mine_field).begin(), (*mine_field).end());
    int max_value = *(*mine_field).begin();
    // remove max value from this field
    // (*mine_field).erase(max_iterator);
    (*mine_field).erase((*mine_field).begin());

    // check if the field is now empty, if so, add 0 to it to mark it as empty
    field_is_empty_after_mining(mine_field);
    cout << "\nDescendron mined " << max_value << " points\n";
    mtx.unlock();
    return max_value;
}

// returns true if there is nothing else to mine in this field
bool Descendron::field_is_empty_before_mining(shared_ptr<field_vector> mine_field) {
    // check if field is empty (top element is 0)
    if (*((*mine_field).begin()) == 0) {
        cout << "\n!! This field is empty. There's nothing else to mine here.\n";
        return true;
    }
    return false;
}

// checks if the field is empty, if so, add 0 to it to mark it as empty
bool Descendron::field_is_empty_after_mining(shared_ptr<field_vector> mine_field) {
    if ((*mine_field).empty()) {
        (*mine_field).push_back(0);
        cout << "\n!! Descendron mined the rest of this field. The field is now empty.\n";
        return true;
    }
    return false;
}

// destroys this object
Descendron::~Descendron() {
    cout << "\nIn Descendron destructor...";
}

// prints this robot
void Descendron::print_robot() {
    cout << "Descendron\n";
}
