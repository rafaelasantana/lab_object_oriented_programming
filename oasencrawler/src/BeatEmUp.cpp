// implements the class BeatEmUp
#include "BeatEmUp.h"

BeatEmUp::BeatEmUp() {

    // create pre-defined fighters
    create_ready_fighters();
    // set the player's fighter
    set_fighter_for_player();
}

// sets a fighter for the player and prints it in the end
void BeatEmUp::set_fighter_for_player() {
    int option;
    // show Fighter options
    print_fighter_options();
    // get player's input
    cin >> option;
    // create a new fighter for player
    if (option == 0) {
        create_new_fighter();
    }
    // set player's fighter to a ready one
    else {
        this->player = get_fighter(option - 1);
    }
    cout << "\n";
    cout << "*** This is your fighter: ***" << endl;
    cout << "\n";
    this->player.print_fighter();
}

// prints the fighter options and asks for the player's input
void BeatEmUp::print_fighter_options() {
    cout << "*** Meet our Fighters! ***" << endl;
    cout << "\n";
    for (int i = 0; i < fighters.size(); i++) {
        cout << "                * OPTION " << i + 1 <<  ": *" << endl;
        get_fighter(i).print_fighter();
    }
    cout << "\n";
    cout << "*** Choose your option (1, 2, 3, 4) or 0 to create a new fighter! ***" << endl;
    cout << "\n";
}

// presents the skill options and player chooses 2 different skills for their fighter
void BeatEmUp::set_fighters_skills() {
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
    // adds skill for the player (fixing index from 1 to 0)
    this->player.add_skill(get_skill(first_skill - 1));

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
    // adds skill for the player (fixing index from 1 to 0)
    this->player.add_skill(get_skill(second_skill - 1));

    cout << "\n";
    cout << "*** Your fighter is ready! ***" << endl;
    cout << "\n";
}

void BeatEmUp::create_new_fighter() {
    string name;
    cout << "\n";
    cout << "*** Let's create your Fighter! Type your name: ***" << endl;
    cout << "\n";
    cin >> name;
    this->player = Fighter(name);
    set_fighters_skills();
}

// creates skills and adds them to the skills list
void BeatEmUp::create_skills() {
    // create the skills
    Skill tailspin("Tailspin", 5, 5);
    Skill skyrocket("Skyrocket", 0, 10);
    Skill barrel_roll("Barrel Roll", 3, 7);
    Skill wingman("Wingman", 8, 2);
    Skill dog_fight("Dog Fight", 7, 3);

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

void BeatEmUp::play_game() {
}

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