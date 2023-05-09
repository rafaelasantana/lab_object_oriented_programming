#include "player.h"

// creates a new player with a robot and sets the maximum position for this game according
// to the mine's max length
Player::Player(shared_ptr<IRobot> robot, int MAX_LENGTH_MINE, string name) {
    this->robot = robot;
    this->points = 0;
    this->MAX_LENGTH_MINE = MAX_LENGTH_MINE;
    this->name = name;
    set_random_position();
}

// an empty constructor (only for game initialization)
Player::Player() {
}

// returns a random starting position for the player and sets the position pointer to this position
shared_ptr<position_array> Player::set_random_position() {
    int random_x = rand() % MAX_LENGTH_MINE;
    int random_y = rand() % MAX_LENGTH_MINE;

    position_array random_position = {random_x, random_y};
    this->position_pointer = make_shared<position_array>(random_position);
    return position_pointer;
}

// prints this player's robot, points and position
void Player::print_player() {
    // get player's position coordinates
    int x_position = (*this->position_pointer)[0];
    int y_position = (*this->position_pointer)[1];

    cout << "\n******* " << this->name << " *******\n";
    cout << "\nRobot: ";
    this->robot->print_robot();
    cout << "\nPoints: " << this->points;
    cout << "\nPosition: ( " << x_position << ", " << y_position << " )";
    cout << "\n******************\n";
}

// returns the shared pointer for the player's position
shared_ptr<position_array> Player::get_position_pointer() {
    return this->position_pointer;
}

// returns this player's points
int Player::get_points() {
    return this->points;
}

// player mines this field and wins ponts. Then the current stats for this player are displayed
void Player::mine_field_and_print_player(shared_ptr<field_vector> field) {
    mtx.lock();
    // get points from the robot's mining
    int mined_points = this->robot->mine(field);
    mtx.unlock();

    // add these points to the player's points
    this->points = points + mined_points;
    // print player's stats
    print_player();
}

