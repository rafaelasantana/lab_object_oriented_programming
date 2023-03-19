#include "RPG.h"

RPG::RPG(int dimension) {
    this->dimension = dimension;
    World new_world(dimension);
    this->w = new_world;
    this->is_active = true;
    play_game();
}

void RPG::play_game() {

    w.add_character(); // add character to the game
    w.add_enemy(); // add enemy

    while (w.character_is_alive() && is_active) {

        // ask for next direction
        char next_move;
        cout << "Choose your next move: 'w' UP, 's' DOWN, 'a' LEFT, 'd' RIGHT or 'x' to EXIT: ";
        cin >> next_move;

        // check user's input and move characters
        if (validated_input(next_move)) {
            // move character
            w.move_character(next_move);
        }
        else {
            cout << "Enter a valid move!" << endl;
        }

        // quit game
        if (next_move == 'x') {
            cout << "Exiting game... " << endl;
            this->is_active = false;
            break;
        }
    }
    is_active = false;
}


void RPG::stop_game() {

}

bool RPG::is_on() {
    return this->is_active;
}

bool RPG::validated_input(char input) {
    return (input == 'a' || input == 's' || input == 'd' || input == 'w' || input == 'x') ? true : false;
}

