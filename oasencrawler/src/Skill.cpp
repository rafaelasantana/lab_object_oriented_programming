// implements the class Skill
#include "Skill.h"
// #include <iostream>
// #include <string>

// int recovery_points;
// int attack_points;

Skill::Skill(string name, int recovery_points, int attack_points) {
    this->name = name;
    this->recovery_points = recovery_points;
    this->attack_points = attack_points;
}

int Skill::get_recovery_points() {
    return recovery_points;
}

int Skill::get_attack_points() {
    return attack_points;
}

// returns 1 if this skill wins, 0 if it's a draw, or -1 if this skill loses
int Skill::fight(Skill other_skill) {
    int other_recovery = other_skill.get_recovery_points();
    int other_attack = other_skill.get_attack_points();

    int diff_attack = attack_points - other_attack;

    int diff_recovery = recovery_points - other_recovery;

    // checks the best combo of attack and recovery in this fight
    int fight_result = diff_attack + diff_recovery;

    // if result is positive, this skill combination wins
    if (fight_result > 1) return 1;
    // if result is 0, the skills match each other and it's a tie
    else if (fight_result == 0) return 0;
    // if the result is negative, the other skill combination wins
    return -1;
}

// prints this skill
void Skill::print() {
    cout << "Skill: " << this->name << " | Attack: " << this->attack_points << " | Recovery: " << this->recovery_points << endl;
}