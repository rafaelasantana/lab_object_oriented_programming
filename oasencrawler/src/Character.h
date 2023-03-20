// defines the class Character
// #include "Fighter.h"
#include "Fighter.cpp"

class Character: public Fighter {
    public:
        Character();
        Character(string name);
        Character(int world_dimension);
        void print();
        void move(char direction);
        void lose_life();
        void win_life();
        void win_relic();
        int get_life_points();
        int get_relics_points();
        bool is_alive();
        void kill_character();
        // void add_skill(Skill* skill);
        // Skill* get_skills();
        ~Character();

    private:
        int life_points, relics_points;
        int x, y, x_max, y_max;
};