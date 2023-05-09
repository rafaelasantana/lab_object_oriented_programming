#include "iRobot.h"

// This Robot class specializes in mining the max value in its x,y-coordinate
// and then sorting the field in ascending order for the opponents.
class MaxGrinder : public IRobot {
    public:
        MaxGrinder();
        int mine(shared_ptr<field_vector> mine_field);
        mutex mtx;
        ~MaxGrinder();
        void print_robot();
        bool field_is_empty_before_mining(shared_ptr<field_vector> mine_field);
        bool field_is_empty_after_mining(shared_ptr<field_vector> mine_field);
};