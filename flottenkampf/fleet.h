#ifndef FLEET_H
#define FLEET_H

#include <vector>
// #include "ship.h"

using namespace std;

class Ship;
class Fleet {
    public:
        Fleet(string name);
        ~Fleet();
        void add_ship(shared_ptr<Ship> ship);
        void print_fleet();
        int get_fleet_size();
        void set_opponent(shared_ptr<Fleet> opponent);
        void play_turn();
        shared_ptr<Ship> get_random_ship();
        void lose_ship(shared_ptr<Ship> ship);
        string get_name();
    private:
        vector<shared_ptr<Ship> > ships;
        shared_ptr<Fleet> opponent;
        string name;
        bool on_battle;
};

#endif
