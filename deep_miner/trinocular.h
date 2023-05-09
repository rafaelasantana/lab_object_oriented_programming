#include "iRobot.h"

// This Robot class uses the value of its coordinates and the next two z-values
// (z = 8 and z = 7) to gather points.
class Trinocular : public IRobot {
    public:
        Trinocular();
        int mine(shared_ptr<field_vector> mine_field);
        ~Trinocular();
        mutex mtx;
        void print_robot();
        bool field_is_empty_before_mining(shared_ptr<field_vector> mine_field);
        bool field_is_empty_after_mining(shared_ptr<field_vector> mine_field);
};