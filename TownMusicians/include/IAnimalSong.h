
#ifndef IANIMALSONG_H
#define IANIMALSONG_H

#include <vector>
#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

class IAnimalSong
{
    public:
        //IAnimalSong();
        //~IAnimalSong();
        virtual int play(vector<shared_ptr<IAnimalSong> > songs, int index) = 0;
        virtual char getTypeChar() = 0;
};

#endif // IANIMALSONG_H
