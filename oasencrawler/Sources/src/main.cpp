#include <iostream>
#include "World.cpp"

bool validated_input(char input) {
    if (input == 'a' || input == 's' || input == 'd' || input == 'w' ) return true;
    return false;
}

int main() {
    int world_dimension = 5;
    World w(world_dimension); // create new world with dimension 5x5
    Character c(world_dimension);

    while (c.is_alive()) {

        // ask for next direction
        char next_move;
        cout << "Choose your next move: 'w' UP, 's' DOWN, 'a' LEFT, 'd' RIGHT, 'x' to EXIT: ";
        cin >> next_move;
        if (validated_input(next_move)) {
            // move character
            c.move(next_move);
            // uncover the field reached by the character
            w.uncover_field(&c);
            // checks on the character's life points and relics
            w.check_character(&c);
        }
        // exit game
        if (next_move == 'x') {
            cout << "Exiting game... " << endl;
            break;
        }
    }

}
