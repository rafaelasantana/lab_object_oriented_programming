// defines the class BeatEmUp
#include "RPG.cpp"

class BeatEmUp {
    public:
        BeatEmUp();
        void play_game();
        bool is_on();
    private:
        // Fighter player;
        // Fighter opponent;
        Fighter player;
        Fighter opponent;
        bool is_active;
        bool validated_fighter_option(int option);
        list<Fighter> fighters;
        list<Skill> skills;
        void fight();
        void create_ready_fighters();
        void create_skills();
        Skill get_skill(int index);
        Fighter get_fighter(int index);
        void print_fighters();
        void set_fighter(int role);
        void print_fighter_options();
        void set_fighters_skills(int role);
        void create_new_fighter(int role);
        bool validated_input_to_start(int input);
};