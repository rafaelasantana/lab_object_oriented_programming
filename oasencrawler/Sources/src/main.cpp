#include <iostream>
#include "World.cpp"

bool validated_input(char input) {
    return (input == 'a' || input == 's' || input == 'd' || input == 'w' || input == 'x') ? true : false;
}

int main() {
    int world_dimension = 5;
    World w(world_dimension); // create new world with dimension 5x5
    w.add_character(); // add character to the game
    w.add_enemy();

    while (w.character_is_alive()) {

        // ask for next direction
        char next_move;
        cout << "Choose your next move: 'w' UP, 's' DOWN, 'a' LEFT, 'd' RIGHT or 'x' to EXIT: ";
        cin >> next_move;

        // check user's input and move character
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
            break;
        }
    }

}
