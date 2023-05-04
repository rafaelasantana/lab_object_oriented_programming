#include "iRobot.h"


// This Robot class specializes in sorting all z-values of its current x- and y-coordinate
// in descending order and then mines the highest value of the order.
class Descendron : public IRobot {
    public:
        Descendron();
        int mine(shared_ptr<field_vector> mine_field);
        ~Descendron();
        shared_ptr<position_array> get_position();
        void print_robot();
    private:
        position_array position;
        shared_ptr<position_array> position_pointer;
};
