#include <iostream>
#include <stdio.h>
#include <vector>
#include <array>
#include <algorithm>
#pragma once

using namespace std;
typedef array<int, 2> position_array;
typedef vector<int> field_vector;

// Robot is an interface tos all Robot miners in DeepMiner.
// Each Robot has its own implementation of the methods from this interface.
// All methods in this interface are pure virtual (using virtual prefix and = 0)
class IRobot {

    public:
        virtual int mine(shared_ptr<field_vector> mine_field) = 0;
        virtual void print_robot() = 0;
    private:
};