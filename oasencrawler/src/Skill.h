// defines the class Skill
#include <string>
using namespace std;

class Skill {
    public:
        Skill(int recovery_points, int attack_points);
        Skill* get_skill();
        int get_recovery_points();
        int get_attack_points();
        int fight(Skill* other);
    private:
        string name;
        int recovery_points;
        int attack_points;
};