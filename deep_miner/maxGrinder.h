#include "iRobot.h"

// This Robot class specializes in finding the max and min values of its x- and y-coordinate.
// It grinds the max value and leaves the min value on the top of the field.
class MaxGrinder : public IRobot {
    public:
        MaxGrinder();
        int mine(shared_ptr<field_vector> mine_field);
        ~MaxGrinder();
        shared_ptr<position_array> get_position();
        void print_robot();
    private:
        position_array position;
        shared_ptr<position_array> position_pointer;
};