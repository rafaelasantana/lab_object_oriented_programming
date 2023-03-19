// defines the class RPG
#include "World.cpp"

class RPG{
    public:
        RPG(int dimension);
        void play_game();
        bool is_on();
        bool validated_input(char input);
    private:
        World w;
        int dimension;
        bool is_active;
};