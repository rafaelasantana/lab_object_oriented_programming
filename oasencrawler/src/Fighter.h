// defines the class Character
// #include "Skill.h"
#include "Skill.cpp"
#include <list>
#include <iterator>

class Fighter {
    public:
        Fighter();
        Fighter(string name);
        Fighter(int world_dimension);
        void move(char direction);
        void move();
        int* get_position();
        int* get_random_position();
        virtual ~Fighter();
        int fight(const Fighter& other);
        virtual void print();
        void print_fighter();
        void add_skill(Skill new_skill);
        list<Skill> get_skills();
        void add_victory();
        void add_defeat();
        void lose_life();
        bool is_alive();
        Skill get_random_skill();
        string get_name();
    protected:
        string name;
        int x, y, x_max, y_max, world_dimension, life_points;
        int victories, defeats;
        list<Skill> skills;
        Skill get_skill(int index);
        void print_error_field_limit();
};
