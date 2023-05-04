#include "player.h"

// creates a new player with a robot and sets the maximum position for this game according
// to the mine's max length
Player::Player(shared_ptr<IRobot> robot, int MAX_LENGTH_MINE, string name) {
    this->robot = robot;
    this->points = 0;
    this->MAX_LENGTH_MINE = MAX_LENGTH_MINE;
    this->name = name;
    this->position = generate_random_starting_position();
    print_player();
}

// an empty constructor (only for game initialization)
Player::Player() {
}

// returns the player's current position
position_array Player::get_position() {
    return this->position;
}

// returns the shared pointer for the player's position
shared_ptr<position_array> Player::get_position_pointer() {
    return this->position_pointer;
}

// returns a random starting position for the player and sets the position pointer to this position
position_array Player::generate_random_starting_position() {
    int random_x = rand() % MAX_LENGTH_MINE;
    int random_y = rand() % MAX_LENGTH_MINE;

    position_array random_position = {random_x, random_y};
    this->position_pointer = make_shared<position_array>(random_position);
    return random_position;
}

// returns this player's points
int Player::get_points() {
    return this->points;
}

// adds mined points to this player's points
void Player::win_points(int mined_points) {
    this->points = points + mined_points;
    cout <<"\nPlayer won " << mined_points << " points! Total Points = " << this->points;
}

// player mines this field and wins ponts. Then the current stats for this player are displayed
void Player::mine_field_and_print_player(shared_ptr<field_vector> field) {
    // get points from the robot's mining
    int won_points = this->robot->mine(field);

    // add these points to the player's points
    cout << "\nPlayer's points before mining = " << this->points << "\n";
    this->points = this->points + won_points;
    cout << "\nPlayer's points after mining = " << this->points << "\n";

    // print player's stats
    print_player();
}

// prints this player
void Player::print_player() {
    // get player's position coordinates
    int x_position = (*this->position_pointer)[0];
    int y_position = (*this->position_pointer)[1];

    cout << "\n*** " << this->name << " ***\n";
    cout << "\nRobot: ";
    this->robot->print_robot();
    cout << "\nPoints: " << this->points;
    cout << "\nPosition: ( " << x_position << ", " << y_position << " )";
    cout << "\n****************\n";
}
