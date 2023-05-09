// for threads: try to compile with
// cd "/Users/rafaelasantana/Documents/FHTW/FHTW_2023SS/obj_oriented_prog/deep_miner/" && g++ main.cpp -o main -std=c++11  -pthread  && "/Users/rafaelasantana/Documents/FHTW/FHTW_2023SS/obj_oriented_prog/deep_miner/"main
#include "deepMinerParallel.cpp"

using namespace std;

int main() {
    // start normal DeepMiner
    // DeepMiner game;

    // start DeepMinerParallel with 5 players
    DeepMinerParallel game(5);
   return 0;
}