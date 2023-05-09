#include "iRobot.h"


// This Robot class specializes in sorting all z-values of its current x- and y-coordinate
// in descending order and then mines the highest value of the order.
class Descendron : public IRobot {
    public:
        Descendron();
        int mine(shared_ptr<field_vector> mine_field);
        mutex mtx;
        ~Descendron();
        void print_robot();
        bool field_is_empty_before_mining(shared_ptr<field_vector> mine_field);
        bool field_is_empty_after_mining(shared_ptr<field_vector> mine_field);
};
