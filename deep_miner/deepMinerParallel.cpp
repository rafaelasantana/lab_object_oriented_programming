#include "deepMinerParallel.h"

// creates a new game with given player count
DeepMinerParallel::DeepMinerParallel(int player_count) : DeepMiner(true) {
    this->player_count = player_count;

    this->total_mined_points = 0;

    setup_game();

    // play game with each player on a thread
    play_game_parallel();

    // play game with all players on the same thread (main)
    // cout << "\nwill play on single thread...\n";
    // play_game_single_thread();
}

// creates players for this game
void DeepMinerParallel::setup_game() {
    // set game status to on
    this->game_is_on = true;
    // get the total points in this game's mine
    this->points_in_game = mine->get_total_points();
    // create players for the game
    create_players();
}

// creates new players for this game and adds them to players vector
void DeepMinerParallel::create_players() {

    for (int id = 1; id <= this->player_count; id++) {
        shared_ptr<Player> player = create_player_with_id(id);
        // add new player to the players vector
        active_players.push_back(player);
    }
}

// creates a new player with an id and ensures the player is alone in a field
shared_ptr<Player> DeepMinerParallel::create_player_with_id(int id) {
    // create robot according to the user's choice
    shared_ptr<IRobot> robot = get_robot_from_users_choice();
    // create a name for player as "P<id>"
    string name = "P" + to_string(id);
    // create new player
    shared_ptr<Player> player = make_shared<Player>(robot, mine->MAX_LENGTH_MINE, name);
    // place player alone in a field that is not empty
    move_player(player);
    return player;
}

// presents robot options to the user and returns the new robot
shared_ptr<IRobot> DeepMinerParallel::get_robot_from_users_choice() {
    // initialize choice with an invalid value
    int choice = 0;

    while(!is_valid_robot_choice(choice)) {
        // present options for robot to the user
        cout << "\n* Choose your Robot: '1' Descendron, '2' MaxGrinder, or '3' Trinocular: \n";
        // get user's choice for robot
        cin >> choice;
        // validate user's choice
        if (!is_valid_robot_choice(choice)) cout << "\nYour choice is not valid. Try again: \n";
    }

    // create new robot according to the choice
    shared_ptr<IRobot> robot = create_robot(choice);
    return robot;
}

// play game with multi threads
void DeepMinerParallel::play_game_parallel() {
    // print total points and players in this game
    print_game_setting();

    // create threads for the players
    thread th0(&DeepMinerParallel::mine_parallel, this, active_players[0]);
    thread th1(&DeepMinerParallel::mine_parallel, this, active_players[1]);
    thread th2(&DeepMinerParallel::mine_parallel, this, active_players[2]);
    thread th3(&DeepMinerParallel::mine_parallel, this, active_players[3]);
    thread th4(&DeepMinerParallel::mine_parallel, this, active_players[4]);

    // join threads
    th0.join();
    th1.join();
    th2.join();
    th3.join();
    th4.join();

    // print final results for this game
    print_final_results();
}

// player mines until the mine is empty
void DeepMinerParallel::mine_parallel(shared_ptr<Player> player) {
    // mine util there are no free fields left
    while (there_are_free_fields_to_mine()) {
        mtx.lock();
        // move player into a new non-empty field alone
        move_player(player);
        // player mines the field
        mine_field(player);
        mine->print_visible_fields();
        mtx.unlock();
    }
    // remove player from players vector
    remove_player_from_game(player);
}

// sets a new position for this player and ensures there is no other player in the same position
void DeepMinerParallel::move_player(shared_ptr<Player> this_player) {
    bool player_is_alone_in_valid_field = false;

    while (!player_is_alone_in_valid_field) {
        // set new random position to this player
        this_player->set_random_position();
        // check if player is alone in this new position
        ensure_player_is_alone_in_field(this_player);
        // exit loop if current field is not empty
        if (!current_field_is_empty(this_player)) {
            player_is_alone_in_valid_field = true;
            break;
        }
    }
}

// play game on single thread alternating turns between players
void DeepMinerParallel:: play_game_single_thread() {
    // print total points and players in this game
    print_game_setting();

    // players mine in alternating turns until the mine is empty
    while (!mine->is_empty()) {
        for (int i = 0; i < active_players.size(); i++) {
            play_game_turn(active_players[i]);
        }
        // print mine after this turn
        mine->print_visible_fields();
    }
}

// prints information about this game in the beginning of the game
void DeepMinerParallel::print_game_setting() {
    cout << "\n*** DEEP MINER PARALLEL ***\n";
    cout << "\n*** TOTAL POINTS TO MINE: " << this->points_in_game << " ***\n";
    cout << "\n*** PLAYERS: ***\n";
    print_players();
    cout << "\n*** READY...? MINE! ***\n";
}

// prints the players in this game
void DeepMinerParallel::print_players() {
    for (int i = 0; i < active_players.size(); i++) {
        shared_ptr<Player> player = active_players[i];
        player->print_player();
    }
}

// player moves into a new field that is not empty and mines it
void DeepMinerParallel::play_game_turn(shared_ptr<Player> player) {
    // move player into a new field alone
    move_computer_player(player);
    ensure_player_is_alone_in_field(player);

    // player mines the field
    mine_field(player);
}

// ensures that this player is alone in a mine field
void DeepMinerParallel::ensure_player_is_alone_in_field(shared_ptr<Player> this_player)
{
    // get current position for this player
    position_array this_position = *(this_player->get_position_pointer());

    // compare this position to all other players' position
    for (shared_ptr<Player> that_player : this->active_players)
    {
        if (this_player != that_player) {
            position_array that_position = *(that_player->get_position_pointer());
            // check if this and that player are in same position
            if (this_position[0] == that_position[0] && this_position[1] == that_position[1]) {
                // set a new position for this player
                move_player(this_player);
            }
        }
    }
}

// returns true if the player's current field is empty
bool DeepMinerParallel::current_field_is_empty(shared_ptr<Player> player) {
    // get player's position
    shared_ptr<position_array> player_position = player->get_position_pointer();
    // get field on that positoin
    shared_ptr<field_vector> field = mine->get_field_pointer(player_position);
    // check if field is empty (top element = 0)
    if (*((*field).begin()) == 0) {
        return true;
    }
    return false;
}

// returns true if there is a non-empty field ini the mine
// that no other player occupies
bool DeepMinerParallel::there_are_free_fields_to_mine() {
    int empty_fields = mine->get_number_empty_fields();
    int total_fields = mine->get_number_fields();
    int free_fields = total_fields - empty_fields;

    // check if there are as many free fields as players
    if (free_fields < active_players.size()) {
        return false;
    }
    return true;
}

// prints the inactivee players that participated in this game with their results
void DeepMinerParallel::print_final_results() {
    cout << "\n*** FINAL RESULTS ***\n";
    cout << "\n*** TOTAL POINTS TO MINE: " << this->points_in_game << " ***\n";
    cout << "\n*** MINED POINTS: " << this->total_mined_points << " ***\n";
    cout <<"\nRemaining points: " << mine->get_remaining_points();
    for (int i = 0; i < inactive_players.size(); i++) {
        shared_ptr<Player> player = inactive_players[i];
        player->print_player();
    }
}

// removes the player from the active players vector
// adds the player to the inactive players vector
void DeepMinerParallel::remove_player_from_game(shared_ptr<Player> player) {
    // add player's points to the mined points
    this->total_mined_points = total_mined_points + player->get_points();
    // remove player from active players
    active_players.erase(remove(active_players.begin(), active_players.end(), player), active_players.end());
    // add player to the inactive players vector
    inactive_players.push_back(player);
    // print that player is out of game
    cout <<"\n!! END OF GAME FOR PLAYER !!";
    player->print_player();
}