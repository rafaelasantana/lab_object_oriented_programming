// defines the class Character

class Character {
    public:
        Character(int world_dimension);
        Character(int world_dimension, bool is_enemy);
        void print_character();
        void print_enemy();
        void move(char direction);
        int* get_position();
        void lose_life();
        void win_life();
        void win_relic();
        int get_life_points();
        int get_relics_points();
        bool is_alive();
        void move_enemy();
        void kill_character();

    private:
        int life_points, relics_points;
        int x, y, x_max, y_max;
};