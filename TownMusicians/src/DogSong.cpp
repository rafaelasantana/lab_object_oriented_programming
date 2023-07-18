
#include "DogSong.h"


DogSong::DogSong() {
    //cout << "\nCreated new DogSong";
};

char DogSong::getTypeChar() {
    return 'D';
}

int DogSong::play(vector<shared_ptr<IAnimalSong> > songs, int index) {
    if (index >= 0 && index < songs.size()) {
        if (index == 0) {
            if (songs[index + 1] != nullptr && songs[index + 1]->getTypeChar() == 'C') return 0;
        }
        else if (index == (songs.size() - 1)) {
            if (songs[index - 1]->getTypeChar() == 'C') return 0;
        }
        else {
            if ((songs[index + 1]->getTypeChar() == 'C') || (songs[index - 1]->getTypeChar() == 'C')) return 0;
        }
        return 1;
    }
    else throw invalid_argument("Invalid index passed to DogSong");
}
