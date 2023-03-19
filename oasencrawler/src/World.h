// defines the class World
#include "Character.cpp"
// #include "Character.h"

class World {
    public:
        World(int dimension);
        void add_character();
        void add_enemy();
        void print_world();
        bool character_is_alive();
        void move_character(char direction);
        ~World();
    private:
        int difficulty_level;
        int dimension;
        int** fields;
        int relics;
        Character* player;
        Fighter* enemy;
        int generate_random_field(int difficulty);
        void clear_field(int x, int y);
        void uncover_field(Character* c);
        void check_character(Character* c);
        void move_enemy();
        void kill_player();
        void fill_world(int difficulty);
};