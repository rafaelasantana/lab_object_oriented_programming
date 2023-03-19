#include <iostream>
#include <list>
#include <iterator>
// #include "World.cpp"
#include "RPG.cpp"
#include "BeatEmUp.cpp"

bool validated_input(char input) {
    return (input == 'a' || input == 's' || input == 'd' || input == 'w' || input == 'x') ? true : false;
}

bool validated_mode(int mode) {
    return (mode == 1 || mode == 2 || mode == 3) ? true : false;
}

bool validated_fighter_option(int option) {
    return (option == 1 || option == 2 || option == 3 ||option == 4) ? true : false;
}

int main() {

    // Skill s1("Margot", 10, 3);
    // Skill s2("Kiko", 3, 10);
    // s1.print();
    // s2.print();

    // list<Skill> li;
    // li.push_back(s1);
    // li.push_back(s2);
    // list<Skill>::iterator it;
    // cout << "printing list..." << endl;
    // for (it = li.begin(); it != li.end(); it++) {
    //     it->print();
    // }

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

    bool game_is_on = true;

    while (game_is_on) {
        int mode;
        cout << "Welcome! Choose your mode: RPG (1), Beat'em up! (2) or Exit Game (3):";
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
                cout << "Welcome to the Beat'em up mode!" << endl;
                bool is_playing = true;
                while (is_playing) {
                    int fighter_option;
                    cout << "Choose your Fighter: " << endl;
                    cout << "Margot (1), Kiko (2), Thor (3), or make your own (4)" << endl;
                    cin >> fighter_option;
                    if (validated_fighter_option(fighter_option)) {
                        cout << "Chosen fighter: " << fighter_option << endl;
                        break;
                    }
                    else {
                        cout << "Enter a valid option!" << endl;
                    }
                }
            }
            else {
                game_is_on = false;
                break;
            }
        }
        else {
            cout << "Enter a valid mode!" << endl;
        }

    }
}
