#include <iostream>
#include <stdio.h>
#include <vector>
#include <array>
#include <memory>
#include "mine.cpp"
#include "descendron.cpp"
#include "trinocular.cpp"
#include "maxGrinder.cpp"
#include "player.cpp"

using namespace std;

class DeepMiner {
    public:
        bool game_is_on;
        DeepMiner();
        ~DeepMiner();
    private:
        int NUMBER_ROBOT_OPTIONS = 3;
        unique_ptr<Mine> mine;
        shared_ptr<IRobot> players_robot;
        shared_ptr<IRobot> computers_robot;
        shared_ptr<Player> user_player;
        shared_ptr<Player> computer_player;
        void set_up_game();
        void set_user_players();
        void set_computer_player();
        void move_user_player();
        void move_computer_player();
        bool is_valid_move_or_quit_option(char input);
        bool is_valid_robot_choice(int choice);
        shared_ptr<IRobot> create_robot(int choice);
        bool checked_direction_and_moved_player(char direction, shared_ptr<Player> player);
        char get_users_input();
        void mine_field(shared_ptr<Player> player);
        void play_game();
        void quit_game();

};