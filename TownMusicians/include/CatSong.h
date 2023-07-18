
#ifndef CATSONG_H
#define CATSONG_H
#include "IAnimalSong.h"

using namespace std;

class CatSong : public IAnimalSong
{
    public:
        CatSong();
        ~CatSong() = default;
        int play(vector<shared_ptr<IAnimalSong> > songs, int index);
        char getTypeChar();
};

#endif // CATSONG_H
