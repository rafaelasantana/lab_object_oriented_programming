// defines the class World
#include "Character.cpp"

class World {
    public:
        World(int dimension);
        void print_world();
        void uncover_field(Character* c);
        void check_character(Character* c);
    private:
        int dimension;
        int** fields;
        int relics;
        int generate_random_field();
        void clear_field(int x, int y);
};