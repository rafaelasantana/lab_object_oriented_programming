#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <memory>
#include "fleet.h"
#pragma once

using namespace std;

// forward declaration of Fleet class
class Fleet;

class Ship {
    public:
        ~Ship() = default;
        virtual void print_ship() = 0;
        virtual int get_size();
        virtual int get_hull();
        virtual int get_damage();
        virtual void suffer_attack();
        virtual bool is_destroyed();
        virtual void attack_ship(shared_ptr<Ship> opponents_ship, shared_ptr<Fleet> opponents_fleet) = 0;
    protected:
        int hull;
        int size;
        int damage;
        virtual void use_special_power() = 0;
};

#endif