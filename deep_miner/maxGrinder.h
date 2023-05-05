#include "iRobot.h"

// This Robot class specializes in mining the max value in its x,y-coordinate
// and then sorting the field in ascending order for the opponents.
class MaxGrinder : public IRobot {
    public:
        MaxGrinder();
        int mine(shared_ptr<field_vector> mine_field);
        ~MaxGrinder();
        void print_robot();
    private:
        position_array position;
        shared_ptr<position_array> position_pointer;
};