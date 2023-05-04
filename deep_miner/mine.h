#include <iostream>
#include <stdio.h>
#include <vector>
#include <array>

using namespace std;
typedef array<int, 2> position_array;
typedef vector<int> field_vector;

class Mine {

    public:
        Mine();
        const int MAX_DEPTH_FIELD = 10;
        const int MAX_LENGTH_MINE = 5;
        void print_visible_fields();
        shared_ptr<field_vector> get_field_pointer(shared_ptr<position_array> position);
        void print_visible_fields_with_players_position(shared_ptr<position_array> user_position, shared_ptr<position_array> computer_position);

    private:
        // array<array<field_vector, 5>, 5> mine_fields;
        array<array<shared_ptr<field_vector>, 5>, 5> mine_fields;
        void fill_fields();

};