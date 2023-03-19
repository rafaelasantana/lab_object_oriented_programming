// defines the class Character
// #include "Skill.h"
#include "Skill.cpp"

class Fighter {
    public:
        Fighter(int world_dimension);
        void move(char direction);
        void move();
        int* get_position();
        int* get_random_position();
        virtual ~Fighter();
        int fight(const Fighter& other);
        int test();
        virtual void print();
    protected:
        int x, y, x_max, y_max, world_dimension;
        Skill* skills;
        int* position;
        void print_error_field_limit();
};
