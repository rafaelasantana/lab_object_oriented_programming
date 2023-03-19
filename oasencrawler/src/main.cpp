#include <iostream>
#include <list>
#include <iterator>
#include "BeatEmUp.cpp"

bool validated_mode(int mode) {
    return (mode == 1 || mode == 2 || mode == 3) ? true : false;
}

int main() {

    bool is_on = true;

    while (is_on) {
        int mode;
        cout << "\n";
        cout << "*** Welcome! Choose your mode: RPG (1), Beat'em up! (2) or Exit Game (3) ***";
        cin >> mode;

        if (validated_mode(mode)) {
            // start RPG Game
            if (mode == 1) {
                cout << "\n";
                cout << "*** Welcome to the RPG Mode! ***" << endl;
                cout << "\n";
                // create new RPG game with dimension 5x5
                RPG game(5);
                bool rpg_is_on = game.is_on();

                // play RPG game
                while (rpg_is_on) {
                    if (game.is_on() == false) {
                        rpg_is_on = false;
                        break;
                    }
                }
                cout << "You exited the RPG mode." << endl;
            }
            // start Beat'em up! game
            else if (mode == 2) {
                cout << "\n";
                cout << "*** Welcome to the Beat'em Up mode! ***" << endl;
                cout << "\n";
                // create new BeatEmUp game
                BeatEmUp game;
                bool fight_is_on = game.is_on();
                // play BeatEmUp game
                while (fight_is_on) {
                    cout << "Entered the loop" << endl;
                    if (game.is_on() == false) {
                        fight_is_on = false;
                        break;
                    }
                }
                cout << "You exited the BeatEmUp mode." << endl;
            }
            // exit
            else {
                is_on = false;
                break;
            }
        }
        else {
            cout << "Enter a valid mode!" << endl;
        }
    }
}
