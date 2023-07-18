#include "RoosterSong.h"

RoosterSong::RoosterSong() {
    //cout << "\nCreated new RoosterSong";
};

char RoosterSong::getTypeChar() {
    return 'R';
}

int RoosterSong::play(vector<shared_ptr<IAnimalSong> > songs, int index) {
    if (index >= 0 && index < songs.size()) {
        int roosterCount = 0;
        for(int i = 0; i < songs.size(); i++) {
            if (songs[i]->getTypeChar() == 'R') roosterCount++;
        }
        if (roosterCount == 1) return 3;
        return 0;

    }
    else throw invalid_argument("Invalid index passed to RoosterSong");
}
