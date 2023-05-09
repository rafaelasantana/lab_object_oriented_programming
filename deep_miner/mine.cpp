#include "mine.h"

// creates a new mine
Mine::Mine() {

    // fill the mine fields with random values between 1-9
    fill_fields();

    // displays the visible fields on the mine
    print_visible_fields();

}

// fills the mine fields with random values between 1-9 and saves the sum of these values in total_points_in_mine
void Mine::fill_fields()
{   
    this->total_points_in_mine = 0;
    this->number_total_fields = 0;
    this->number_empty_fields = 0;
    // iterate through mine positions
    for (int x = 0; x < MAX_LENGTH_MINE; x++)
    {

        for (int y = 0; y < MAX_LENGTH_MINE; y++)
        {
            // get current field
            shared_ptr<field_vector> current_field = make_shared<field_vector>();

            // fill field with values between 1-9
            for (int depth = 0; depth < MAX_DEPTH_FIELD; depth++)
            {
                // get random value betweeen 1 and 9
                int random = (rand() % 9) + 1;
                // add it to the field
                current_field->push_back(random);
                // add this value to the total points in this mine
                this->total_points_in_mine = total_points_in_mine + random;
            }
            // increase the number of total fields by 1
            this->number_total_fields++;

            // update mine_fields with new values for current field
            mine_fields[x][y] = current_field;
        }
    }
}

// returns the pointer to the field in this position
shared_ptr<field_vector> Mine::get_field_pointer(shared_ptr<position_array> position_pointer) {

    // get coordinates for this position
    int x_position = (*position_pointer)[0];
    int y_position = (*position_pointer)[1];

    // iterate through mine positions
    for (int x = 0; x < MAX_LENGTH_MINE; x++)
    {
        for (int y = 0; y < MAX_LENGTH_MINE; y++)
        {
            // get current field pointer
            shared_ptr<field_vector> field_pointer = mine_fields[x][y];

            // check if current field is in the requested position
            if (x == x_position && y == y_position) {
                // return this pointer
                return field_pointer;
            }
        }
    }
}

// prints the top layer of this mine
void Mine::print_visible_fields() {

    cout << "\n**** MINE ****\n";

    for (int y = MAX_LENGTH_MINE - 1; y >= 0; y--) {
        // print one row at a time, from top to bottom
        string row_of_fields_top_values = "\n";

        for (int x = 0; x < MAX_LENGTH_MINE; x++) {
            shared_ptr<field_vector> current_field = mine_fields[x][y];
            // get first (top) element of this field
            auto top_element = current_field->begin();
            // add element to the row
            row_of_fields_top_values += to_string(*top_element) + "  ";
        }

        cout << row_of_fields_top_values + "\n";

    }
}

// prints the top layer of this mine with a highlight on the user's and computer's position
void Mine::print_visible_fields_with_players_position(shared_ptr<position_array> user_position, shared_ptr<position_array> computer_position) {
    // get coordinates for the user's position
    int user_selected_x = (*user_position)[0];
    int user_selected_y = (*user_position)[1];

    // get coordinates for the computer's position
    int computer_selected_x = (*computer_position)[0];
    int computer_selected_y = (*computer_position)[1];

    cout << "\n  ******* MINE *******\n";

    for (int y = MAX_LENGTH_MINE - 1; y >= 0; y--) {
        // print one row at a time, from top to bottom
        string row_of_fields_top_values = "\n";

        for (int x = 0; x < MAX_LENGTH_MINE; x++) {

            shared_ptr<field_vector> current_field = mine_fields[x][y];
            // get first (top) element of this field
            auto top_element = current_field->begin();

            // if this is the selected field for the user, mark it with * around it
            if (x == user_selected_x && y == user_selected_y) {
                row_of_fields_top_values += "* " + to_string(*top_element) + " *";
            }
            // if this is the selected field for the computer, mark it with | around it
            else if (x == computer_selected_x && y == computer_selected_y) {
                row_of_fields_top_values += "| " + to_string(*top_element) + " |";
            }
            // if it's not the selected field, print it as usual
            else {
                // add element to the row
                row_of_fields_top_values += "  " + to_string(*top_element) + "  ";
            }
        }

        cout << row_of_fields_top_values + "\n";
    }
}

// returns the total points in this mine's fields
int Mine::get_total_points() {
    return this->total_points_in_mine;
}

// returns true if there is at least one field not empty
bool Mine::is_empty() {
    // try to find a field that is not empty
    for (int x = 0; x < MAX_LENGTH_MINE; x++)
    {
        for (int y = 0; y < MAX_LENGTH_MINE; y++)
        {
            // get current field
            shared_ptr<field_vector> current_field = mine_fields[x][y];

            // check if field is not empty (top element != 0)
            if (*((*current_field).begin()) != 0) {
                return false;
            }
        }
    }
    return true;
}

int Mine::get_remaining_points() {
    int points = 0;
    // iterate through mine positions
    for (int x = 0; x < MAX_LENGTH_MINE; x++)
    {

        for (int y = 0; y < MAX_LENGTH_MINE; y++)
        {
            // get current field
            shared_ptr<field_vector> current_field = mine_fields[x][y];

            // fill field with values between 1-9
            for (int depth = 0; depth < (*current_field).size(); depth++)
            {
                points = points + (*current_field)[depth];
            }
        }
    }
    return points;
}

// returns the number of empty fields in this mine
int Mine::get_number_empty_fields() {
    return this->number_empty_fields;
}

// returns the total number of fields on the mine
int Mine::get_number_fields() {
    return this->number_total_fields;
}

// checks if the mined field is empty and if so, increases the number of empty fields
void Mine::update_mine_status(shared_ptr<field_vector> mined_field) {
    if (*((*mined_field).begin()) == 0) {
        this->number_empty_fields++;
    }
}