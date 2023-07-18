
#ifndef ROOSTERSONG_H
#define ROOSTERSONG_H
#include "IAnimalSong.h"

using namespace std;

class RoosterSong : public IAnimalSong
{
    public:
        RoosterSong();
        ~RoosterSong() = default;
        int play(vector<shared_ptr<IAnimalSong> > songs, int index);
        char getTypeChar();
};

#endif // ROOSTERSONG_H
