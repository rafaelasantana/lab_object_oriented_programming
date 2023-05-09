#include "deepMiner.cpp"
#include <thread>

class DeepMinerParallel : public DeepMiner {
    public:
        DeepMinerParallel(int player_count);
    private:
        bool game_is_on;
        vector<shared_ptr<Player> > active_players;
        vector<shared_ptr<Player> > inactive_players;
        void create_players();
        vector<thread> player_threads;
        shared_ptr<Player> create_player_with_id(int id);
        int player_count;
        int points_in_game;
        int total_mined_points;
        shared_ptr<IRobot> get_robot_from_users_choice();
        void setup_game();
        void print_players();
        void print_game_setting();
        bool current_field_is_empty(shared_ptr<Player> player);
        void ensure_player_is_alone_in_field(shared_ptr<Player> this_player);
        void move_player(shared_ptr<Player> this_player);
        bool there_are_free_fields_to_mine();
        void play_game_turn(shared_ptr<Player> player);
        void mine_parallel(shared_ptr<Player> player);
        void remove_player_from_game(shared_ptr<Player> player);
        void play_game_parallel();
        void play_game_single_thread();
        void print_final_results();
};