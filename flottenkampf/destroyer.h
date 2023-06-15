#ifndef DESTROYER_H
#define DESTROYER_H

#include "ship.h"

class Destroyer : public Ship {
    public:
        Destroyer();
        ~Destroyer();
        void print_ship() override;
        int get_size();
        int get_hull();
        int get_damage();
        void suffer_attack();
        bool is_destroyed();
        void attack_ship(shared_ptr<Ship> opponents_ship, shared_ptr<Fleet> opponents_fleet);
    private:
        void use_special_power() override;
};

#endif