// defines the class Character

class Character {
    public:
        Character(int world_dimension);
        void print_character();
        void move(char direction);
        int* get_position();
        void lose_life();
        void win_life();
        void win_relic();
        int get_life_points();
        int get_relics_points();
        bool is_alive();
    private:
        int life_points, relics_points;
        int x, y, x_max, y_max;
};