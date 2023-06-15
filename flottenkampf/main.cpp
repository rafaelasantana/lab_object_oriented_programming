#include <iostream>
#include <memory>
#include "cruiser.cpp"
#include "hunter.cpp"
#include "destroyer.cpp"
#include "fleet.cpp"

using namespace std;

// returns true if the user's chosen action is valid
bool action_choice_is_valid(char choice)
{
    return (choice == 'c' || choice == 'h' || choice == 'd' || choice == 'x') ? true : false;
}

// returns a valid action choice from the user
char get_users_action_choice() {
    // get user's choice
    char choice;
    cout << "\n-> Choose a ship: Cruiser 'c', Hunter 'h', Destroyer 'd' or 'x' if your fleet is complete:\n";
    cin >> choice;

    // check if choice if valid
    while (!action_choice_is_valid(choice))
    {
        cout << "\n!! Choose a valid option!\n";
        cout << "\n-> Choose a ship: Cruiser 'c', Hunter 'h', Destroyer 'd' or 'x' if your fleet is complete:\n";
        cin >> choice;
    }

    return choice;
}

// returns a Ship pointer according to the user's choice
shared_ptr<Ship> create_chosen_ship(char choice) {
    shared_ptr<Ship> new_ship;

    switch (choice)
    {
    case 'c':
        new_ship = make_shared<Cruiser>();
        break;
    case 'h':
        new_ship = make_shared<Hunter>();
        break;
    case 'd':
        new_ship = make_shared<Destroyer>();
        break;
    }
    return new_ship;
}

// returns a Fleet pointer with 1 to 9 ships chosen by the user
shared_ptr<Fleet> create_fleet(string name)
{
    shared_ptr<Fleet> fleet = make_shared<Fleet>(name);
    bool fleet_is_complete = false;

    // create a fleet with min 1 and max 9 ships
    for (int i = 0; i < 9; i++)
    {
        // check if fleet is already complete
        if (!fleet_is_complete)
        {
            // get user's action choice
            char choice = get_users_action_choice();

            // check if user set the fleet as complete
            if (choice == 'x') {
                // if there are no ships in the fleet yet, warn user
                if (fleet->get_fleet_size() < 1)
                {
                    cout << "\n!! Your fleet needs at least one ship to be complete.\n";
                }
                // set fleet as complete
                else
                {
                    fleet_is_complete = true;
                    break;
                }
            }

            // create new ship according to user's choice
            shared_ptr<Ship> new_ship = create_chosen_ship(choice);

            // add new ship to the fleet
            fleet->add_ship(new_ship);
        }
        // exit for loop if fleet is complete
        else
            break;
    }

    return fleet;
}

int main()
{
    cout << "\nStarting game...\n";

    cout << "\nCreate the first Fleet:\n";
    shared_ptr<Fleet> first_fleet = create_fleet("A");

    cout << "\nCreate the second Fleet:\n";
    shared_ptr<Fleet> second_fleet = create_fleet("B");

    cout << "\nFirst Fleet:\n";
    first_fleet->print_fleet();

    cout << "\nSecond Fleet:\n";
    second_fleet->print_fleet();

    // set opponents
    first_fleet->set_opponent(second_fleet);
    second_fleet->set_opponent(first_fleet);

    // play turn
    cout << "\nPlaying turn...\n";
    first_fleet->play_turn();

    return 0;
}