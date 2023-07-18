#include "CatSong.h"


CatSong::CatSong() {
    //cout << "\nCreated new CatSong";
};

char CatSong::getTypeChar() {
    return 'C';
}

int CatSong::play(vector<shared_ptr<IAnimalSong> > songs, int index) {
    if (index >= 0 && index < songs.size()) {
        int dogCount = 0;
        for(int i = 0; i < index; i++) {
            shared_ptr<IAnimalSong> animal = songs[i];
            if (animal->getTypeChar() == 'D') dogCount++;
        }
        return 5 - dogCount;
    }
    else throw invalid_argument("Invalid index passed to CatSong");
}
