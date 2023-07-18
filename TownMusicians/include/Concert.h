#ifndef CONCERT_H
#define CONCERT_H

#include <iostream>
#include <vector>
#include <memory>

#include "DogSong.h"
#include "CatSong.h"
#include "RoosterSong.h"
#include "IAnimalSong.h"

using namespace std;

class Concert
{
    public:
        Concert(string songString);
        ~Concert() = default;
        int play();

    protected:

    private:
        vector<shared_ptr<IAnimalSong> > songs;
};

#endif // CONCERT_H
