#include "iRobot.h"

// This Robot class uses the value of its coordinates and the next two z-values
// (z = 8 and z = 7) to gather points.
class Trinocular : public IRobot {
    public:
        Trinocular();
        int mine(shared_ptr<field_vector> mine_field);
        ~Trinocular();
        shared_ptr<position_array> get_position();
        void print_robot();
    private:
        position_array position;
        shared_ptr<position_array> position_pointer;
};