#include <iostream>
#include "World.cpp"

bool validated_input(char input) {
    return (input == 'a' || input == 's' || input == 'd' || input == 'w' || input == 'x') ? true : false;
}

int main() {

    // Character c(4);
    // c.print();
    // // c.move('w');
    // // c.move('d');

    // Fighter f(6);
    // f.print();

    // Fighter f2(4);
    // f2.print();

    // Fighter f3(4);
    // f3.print();


    int world_dimension = 5;
    World w(world_dimension); // create new world with dimension 5x5
    w.add_character(); // add character to the game
    w.add_enemy(); // add enemy

    while (w.character_is_alive()) {

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
            break;
        }
    }
}
