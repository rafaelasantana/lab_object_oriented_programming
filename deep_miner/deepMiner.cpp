#include "deepMiner.h"

using namespace std;

// creates a new DeepMiner game
DeepMiner::DeepMiner() {
    set_up_game();

    play_game();
}

// sets the mine and robots for the player and computer and the possible moves for this game
void DeepMiner::set_up_game() {
    // set game status to on
    this->game_is_on = true;

    // create a new mine for this game
    this->mine = unique_ptr<Mine> (new Mine);

    // set a robot for the player
    set_user_players();

    // set a robot for the computer
    set_computer_player();
}

// sets a robot for the computer to play against the player
void DeepMiner::set_computer_player() {
    // get a random choice for the computer's robot
    int computer_robot_choice = (rand() % NUMBER_ROBOT_OPTIONS) + 1;

    // create robot for computer
    this->computers_robot = create_robot(computer_robot_choice);

    // create player with this robot for the computer and call it 'OPPONENT'
    shared_ptr<Player> computer_player = make_shared<Player>(this->computers_robot, mine->MAX_LENGTH_MINE, "OPPONENT");

    // set the computer player to the newly created player
    this->computer_player = computer_player;
}

// presents robot options to the player and sets player's robot accordingly.
void DeepMiner::set_user_players() {
    bool robot_is_set = false;

    // present options for robot to the user
    while(!robot_is_set) {

        // get user's choice for robot
        int choice;
        cout << "\n* Choose your Robot: '1' Descendron, '2' MaxGrinder, or '3' Trinocular: \n";
        cin >> choice;

        // validate user's choice
        if (is_valid_robot_choice(choice)) {
            this->players_robot = create_robot(choice);
            robot_is_set = true;
            break;
        }
        else cout << "\nYour choice is not valid. Try again: \n";
    }

    // create new player for the user with the chosen robot and call it 'YOU'
    shared_ptr<Player> user_player = make_shared<Player>(this->players_robot, mine->MAX_LENGTH_MINE, "YOU");

    // set the user player to this player
    this->user_player = user_player;
}

// returns a shared pointer to the new robot created according to the choice
shared_ptr<IRobot>DeepMiner::create_robot(int choice) {
    shared_ptr<IRobot> shared_robot_pointer;

    switch (choice) {
        case 1:
            shared_robot_pointer = make_shared<Descendron>();
            break;
        case 2:
            shared_robot_pointer = make_shared<MaxGrinder>();
            break;
        case 3:
            shared_robot_pointer = make_shared<Trinocular>();
            break;
        // if accepted invalid input, quit game and check is_valid_robot_choice function
        default:
            cout << "\n Accepted invalid input. Check is_valid_robot_choice function\n";
            quit_game();
            break;
    }

    return shared_robot_pointer;
}

// quits the game by setting game_is_on to false
void DeepMiner::quit_game(){
    cout << "\nQuitting game...\n";
    this->game_is_on = false;
}

// destroys this DeepMiner object
DeepMiner::~DeepMiner() {
    cout << "\nIn DeepMiner destructor...\n";
}

// checks if the player's move is valid or if the player asked to quit ('x')
bool DeepMiner::is_valid_move_or_quit_option(char input) {
    return (input == 'w' || input == 's' ||  input == 'a' ||  input == 'd' ||  input == 'r' ||  input == 'x') ? true : false;
}

// checks if the player's choice for robot is valid
bool DeepMiner::is_valid_robot_choice(int choice) {
    return (choice > 0 && choice <= NUMBER_ROBOT_OPTIONS) ? true : false;
}

// displays the input options and returns the player's input
char DeepMiner::get_users_input() {
    char input;
    cout << "\n* Choose a direction to move: 'w' (up), 's' (down), 'a' (left), 'd' (right), 'r' (stay) or 'x' to quit the game: \n";
    cin >> input;
    cout << "\n Chosen direction: " << input << "\n";
    return input;
}

// plays game alternating turns between user and computer
void DeepMiner::play_game() {

    while (this->game_is_on) {

        // print mine highlighting the positions from user player and computer player
        mine->print_visible_fields_with_players_position(this->user_player->get_position_pointer(), this->computer_player->get_position_pointer());

        // move the user player
        move_user_player();

        // user player mines the field
        mine_field(this->user_player);

        // move the computer player
        move_computer_player();

        // computer player mines the field
        mine_field(this->computer_player);
    }
}

// moves the computer player in a valid direction
void DeepMiner::move_computer_player() {
    bool moved_computer = false;
    char possible_directions[] = {'w', 's', 'a', 'd', 'r'};

    while (!moved_computer) {
        // get a random direction to move
        int random_index = rand() % 5;
        char direction = possible_directions[random_index];

        // check if this direction is valid and if so, move player
        moved_computer = checked_direction_and_moved_player(direction, this->computer_player);
    }
}

// moves the player in a valid direction or quits the game
void DeepMiner::move_user_player() {
    bool moved_player = false;

    // move player in a valid direction or quit the game
    while (!moved_player) {
        char input = get_users_input();

        // check if the input is valid to move player
        if (is_valid_move_or_quit_option(input)) {
            // quit game if player requested so
            if (input == 'x') {
                quit_game();
                break;
            }
            // if input is a valid direction, move player in this direction
            moved_player = checked_direction_and_moved_player(input, this->user_player);

            // if input is not a valid direction, ask for a new input
            if (!moved_player) cout << "\n!! You cannot move in this direction. Try a different one: \n";
        }
        // if input is not valid, ask for a new one
        else cout << "\nInvalid input! Try again:";
    }
}

// returns true if the requested direction is valid in the mine setting and the player moved in this direction.
bool DeepMiner::checked_direction_and_moved_player(char direction, shared_ptr<Player> player) {

    int max_position = mine->MAX_LENGTH_MINE - 1;
    int min_position = 0;
    bool moved_player = false;
    shared_ptr<position_array> current_position = player->get_position_pointer();

    // check if requested direction is valid. If so, move the player in this direction
    switch(direction) {
        // asked to move up, check y-coordinate and move if it's valid
        case 'w':
            if ((*current_position)[1] < max_position) {
                (*current_position)[1] = (*current_position)[1] + 1;
                moved_player = true;
            }
            break;
        // asked to move down, check y-coordinate and move if it's valid
        case 's':
            if ((*current_position)[1] > min_position){
                (*current_position)[1] = (*current_position)[1] - 1;
                moved_player = true;
            }
            break;
        // asked to move left, check x-coordinate and move if it's valid
        case 'a' :
            if ((*current_position)[0] > min_position) {
                (*current_position)[0] = (*current_position)[0] - 1;
                moved_player = true;
            }
            break;
        // asked to move right, check x-coordinate
        case 'd':
            if ((*current_position)[0] < max_position) {
                (*current_position)[0] = (*current_position)[0] + 1;
                moved_player = true;
            }
            break;
        // asked to stay in the same coordinates
        case 'r':
            moved_player = true;
            break;
        // game accepted invalid direction, quit game to check is_valid_input function
        default:
            cout << "\n!! Invalid direction! Error in is_valid_input function\n";
            quit_game();
            break;
    }

    return moved_player;
}

// player mines the current field it's on and wins points
void DeepMiner::mine_field(shared_ptr<Player> player) {
    // get player's position
    shared_ptr<position_array> player_position = player->get_position_pointer();

    // get field on that positoin
    shared_ptr<field_vector> field = mine->get_field_pointer(player_position);

    // mine field
    player->mine_field_and_print_player(field);
}