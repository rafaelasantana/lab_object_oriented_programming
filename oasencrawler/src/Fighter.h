// defines the class Character
// #include "Skill.h"
#include "Skill.cpp"
#include <list>
#include <iterator>

class Fighter {
    public:
        Fighter(int world_dimension);
        void move(char direction);
        void move();
        int* get_position();
        int* get_random_position();
        virtual ~Fighter();
        int fight(const Fighter& other);
        virtual void print();
        void add_skill(Skill new_skill);
        list<Skill> get_skills();
    protected:
        int x, y, x_max, y_max, world_dimension;
        list<Skill> skills;
        int* position;
        void print_error_field_limit();
};
