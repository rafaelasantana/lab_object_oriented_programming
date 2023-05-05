#include <iostream>
#include <stdio.h>
#include <vector>
#include <array>
#include "iRobot.h"

using namespace std;
typedef array<int, 2> position_array;
typedef vector<int> field_vector;

class Player {
    public:
        Player();
        Player(shared_ptr<IRobot> robot, int MAX_LENGTH_MINE, string name);
        shared_ptr<position_array> get_position_pointer();
        int get_points();
        void print_player();
        void mine_field_and_print_player(shared_ptr<field_vector> field);
    private:
        position_array generate_random_starting_position();
        shared_ptr<position_array> position_pointer;
        position_array position;
        shared_ptr<IRobot> robot;
        int points;
        int max_position;
        int MAX_LENGTH_MINE;
        string name;
};