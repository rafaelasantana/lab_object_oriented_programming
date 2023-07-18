#include "Concert.h"

Concert::Concert(string songString)
{
    for(char s : songString)
    {
        shared_ptr<IAnimalSong> newAnimal;
        switch(s)
        {
            case 'C':
                newAnimal = make_shared<CatSong>();
                break;
            case 'D':
                newAnimal = make_shared<DogSong>();
                break;
            case 'R':
                newAnimal = make_shared<RoosterSong>();
        }
        songs.push_back(newAnimal);
    }
}

int Concert::play() {
    int total = 0;
    for(int i = 0; i < songs.size(); i++) {
        shared_ptr<IAnimalSong> song = songs[i];
        try {
            total += song->play(songs, i);
        }
        catch(const invalid_argument& e) {
            cout << e.what();
        }
    }
    return total;
}
