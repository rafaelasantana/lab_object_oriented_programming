// defines the class Skill
#include <iostream>
#include <string>
using namespace std;

class Skill {
    public:
        Skill(string name, int recovery_points, int attack_points);
        // Skill* get_skill();
        int get_recovery_points();
        int get_attack_points();
        int fight(Skill* other);
        void print();
    private:
        string name;
        int recovery_points;
        int attack_points;
};