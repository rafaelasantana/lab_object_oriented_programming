// implements the class BeatEmUp
#include "BeatEmUp.h"

BeatEmUp::BeatEmUp() {

    // create pre-defined fighters
    create_ready_fighters();

    // start game
    this->is_active = true;
    play_game();
}

// sets a fighter for the player (role = 0) or opponent (role = 1)
void BeatEmUp::set_fighter(int role) {
    int option;
    // show Fighter options
    print_fighter_options();
    // get player's input
    cin >> option;
    // create a new fighter for the role
    if (option == 0) {
        create_new_fighter(role);
    }
    // set fighter to a ready one (fixing index)
    else {
        if (role == 0) {
            this->player = get_fighter(option - 1);
        }
        else if (role == 1) {
            this->opponent = get_fighter(option - 1);
        }
    }
    // print the fighter
    if (role == 0) {
        cout << "\n";
        cout << "*** This is your fighter: ***" << endl;
        cout << "\n";
        this->player.print_fighter();
        if (option == 0) {
            fighters.push_back(this->player);
        }
    }
    // print the opponent
    else if (role == 1) {
        cout << "\n";
        cout << "*** This is your opponent: ***" << endl;
        cout << "\n";
        this->opponent.print_fighter();
        if (option == 0) {
            fighters.push_back(this->opponent);
        }
    }
}

// prints the fighter options and asks for the player's input
void BeatEmUp::print_fighter_options() {
    cout << "*** Meet our Fighters! ***" << endl;
    cout << "\n";
    string options = "(";
    for (int i = 0; i < fighters.size(); i++) {
        cout << "                * OPTION " << i + 1 <<  ": *" << endl;
        get_fighter(i).print_fighter();
        if (i == fighters.size() - 1) {
            options = options + to_string(i + 1) + ")";
        }
        else {
            options = options + to_string(i + 1) + ", ";

        }
    }
    cout << "\n";
    cout << "*** Choose your option " << options <<" or 0 to create a new fighter! ***" << endl;
    cout << "\n";
}

// presents the skill options and player chooses 2 different skills for their new fighter
void BeatEmUp::set_fighters_skills(int role) {
    Fighter new_fighter;
    if (role == 0) {
        new_fighter = this->player;
    }
    else if (role == 1) {
        new_fighter = this->opponent;
    }

    int first_skill;
    int second_skill;
    // present available skills
    cout << "\n";
    cout << "*** These are the available skills. Choose two different for your fight! ***" << endl;
    cout << "\n";
    for (int i = 0; i < skills.size(); i++) {
        cout << "            * OPTION " << i + 1 <<  ": *" << endl;
        get_skill(i).print();
        cout << "\n";
    }
    // ask for the first skill
    cout << "\n";
    cout << "*** Choose your first skill (1, 2, 3, 4, 5): ***" << endl;
    cout << "\n";
    cin >> first_skill;

    // adds skill for the fighter (fixing index from 1 to 0)
    new_fighter.add_skill(get_skill(first_skill - 1));

    // ask for the second skill
    bool are_different = false;
    while (!are_different) {
        cout << "\n";
        cout << "*** Choose your second skill, different from the first one: ***" << endl;
        cout << "\n";
        cin >> second_skill;
        if (second_skill != first_skill) {
            are_different = true;
            break;
        }
    }
    // adds skill for the fighter (fixing index from 1 to 0)
    new_fighter.add_skill(get_skill(second_skill - 1));

    cout << "\n";
    cout << "*** Your fighter is ready! ***" << endl;
    cout << "\n";

    if (role == 0) {
        this->player = new_fighter;
    }
    else if (role == 1) {
        this->opponent = new_fighter;
    }
}

// creates a new fighter for player (role = 0) or opponent (role = 1) and adds it to the fighters list
void BeatEmUp::create_new_fighter(int role) {
    string name;
    cout << "\n";
    cout << "*** Let's create your Fighter! Type your name: ***" << endl;
    cout << "\n";
    cin >> name;
    Fighter new_fighter = Fighter(name);

    // set new fighter to the player
    if (role == 0) {
        this->player = new_fighter;
        set_fighters_skills(0);
    }
    // set new fighter to the opponent
    else if (role == 1) {
        this->opponent = new_fighter;
        set_fighters_skills(1);
    }
}

// creates skills and adds them to the skills list
void BeatEmUp::create_skills() {
    // create the skills
    Skill tailspin("Tailspin", 5, 7);
    Skill skyrocket("Skyrocket", 0, 10);
    Skill barrel_roll("Barrel Roll", 5, 7);
    Skill wingman("Wingman", 8, 1);
    Skill dog_fight("Dog Fight", 7, 1);

    // add to skills list
    this->skills.push_front(tailspin);
    this->skills.push_front(skyrocket);
    this->skills.push_front(barrel_roll);
    this->skills.push_front(wingman);
    this->skills.push_front(dog_fight);
}

// create ready-to-use fighters and adds them to the fighters list
void BeatEmUp::create_ready_fighters() {
    // // create skills
    create_skills();

    // create Margot
    Fighter margot("Margot");
    margot.add_skill(get_skill(0));
    margot.add_skill(get_skill(1));
    fighters.push_back(margot);

    // create Kiko
    Fighter kiko("Kiko");
    kiko.add_skill(get_skill(1));
    kiko.add_skill(get_skill(2));
    fighters.push_back(kiko);

    // create Thor
    Fighter thor("Thor");
    thor.add_skill(get_skill(2));
    thor.add_skill(get_skill(3));
    fighters.push_back(thor);

    // create Lily
    Fighter lily("Lily");
    lily.add_skill(get_skill(3));
    lily.add_skill(get_skill(4));
    fighters.push_back(lily);
}

// returns the skill at index on skills list
Skill BeatEmUp::get_skill(int index) {
    list<Skill>::iterator it = skills.begin();
    for(int i=0; i < skills.size(); i++) {
        if (i == index) return *it;
        it++;
    }
    return Skill("null skill, check your code!!", 0, 0);
}

// returns the fighter at index on fighters list
Fighter BeatEmUp::get_fighter(int index) {
    list<Fighter>::iterator it = fighters.begin();
    for(int i=0; i < fighters.size(); i++) {
        if (i == index) return *it;
        ++it;
    }
    return Fighter("null fighter, check your code!");
}

// plays the game or exits upon user request
void BeatEmUp::play_game() {

    while (is_active) {
        int input;
        cout << "\n";
        cout << "*** Choose (1) to start a REAL FIGHT or (0) to exit the game ***" << endl;
        cout << "\n";
        cin >> input;
        // check if input is valid
        if (validated_input_to_start(input)) {
            // start game
            if (input == 1) {
                 // set the player's fighter (role = 0)
                set_fighter(0);
                // player chooses opponent
                cout << "\n";
                cout << "*** Now it's time to choose your opponent! ***" << endl;
                cout << "\n";
                // set the player's opponent (role = 1)
                set_fighter(1);
                // fight player x opponent until one loses
                fight();
                // store fight results (see wins and losts of all characters)
                //print_fighter_options();
                // after fight is over, give option to start another fight
            }
            else {
                is_active = false;
                break;
            }
        }
        else {
            cout << "\n";
            cout << "*** Enter a valid option! ***" << endl;
            cout << "\n";
        }
    }
    cout << "\n";
    cout << "*** You exited the BeatEmUp mode ***" << endl;
    cout << "\n";
}

// returns if this game is active
bool BeatEmUp::is_on() {
    return this->is_active;
}

bool BeatEmUp::validated_fighter_option(int option) {
    return (option == 1 || option == 2 || option == 3 ||option == 4) ? true : false;
}

// prints the fighters in this game
void BeatEmUp::print_fighters() {
    list<Fighter>::iterator it = fighters.begin();
    for(int i=0; i < fighters.size(); i++) {
        Fighter current = *it;
        current.print_fighter();
        ++it;
    }
}

// player fights the opponent
void BeatEmUp::fight() {

    Fighter champion;

    // skills fight as long as both fighters are alive
    while (player.is_alive() && opponent.is_alive()) {

        // get a random skill for fighters
        Skill player_skill = this->player.get_random_skill();
        Skill opponent_skill = this->opponent.get_random_skill();

        cout << "\n";
        cout << this->player.get_name() << " fights with ";
        player_skill.print();
        cout << this->opponent.get_name() << " fights with ";
        opponent_skill.print();
        cout << "\n";

        // skills fight
        int result = player_skill.fight(opponent_skill);

        // player wins
        if (result == 1) {
            this->opponent.lose_life();
            cout << "\n";
            cout << "*** " << this->player.get_name() << " wins this round! ***" << endl;
            cout << "\n";
        }
        // opponent wins
        else if (result == -1) {
            this->player.lose_life();
            cout << "\n";
            cout << "*** " << this->opponent.get_name() << " wins this round! ***" << endl;
            cout << "\n";
        }
        // it's a draw, both lose a life point
        else {
            cout << "\n";
            cout << "*** TOUGH FIGHT! It's a tie and both fighters lose a life! ***" << endl;
            cout << "\n";
            this->player.lose_life();
            this->opponent.lose_life();
        }
    }
    // player won
    if (this->player.is_alive()) {
        this->player.add_victory();
        this->opponent.add_defeat();
        champion = this->player;
    }
    // opponent won
    else {
        this->opponent.add_victory();
        this->player.add_defeat();
        champion = this->opponent;
    }
    // restore life points from fighters
    this->player.restore_life_points();
    this->opponent.restore_life_points();
    // print winner
    cout << "\n";
    cout << "*** " << champion.get_name() << " IS THE WINNER! ***" << endl;
    cout << "\n";
}

// validates input to start the game
bool BeatEmUp::validated_input_to_start(int input) {
    return (input == 0 || input == 1) ? true : false;
}