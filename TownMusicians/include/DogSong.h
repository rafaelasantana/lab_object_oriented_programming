
#ifndef DOGSONG_H
#define DOGSONG_H
#include "IAnimalSong.h"

using namespace std;

class DogSong : public IAnimalSong
{
    public:
        DogSong();
        ~DogSong() = default;
        int play(vector<shared_ptr<IAnimalSong> > songs, int index);
        char getTypeChar();
};

#endif // DOGSONG_H

