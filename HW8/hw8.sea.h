#ifndef SEA_H_INCLUDED
#define SEA_H_INCLUDED

#include <vector>
#include "hw8.shark.h"

#define SIZE 5
#define INIT_NUM_FISH 10
#define INIT_NUM_SHARK 5

class Sea {
public:
    Sea();
    void SimulateOneStep();
    void Print();
    void PopulationCensus(int& nshark, int& nfish);
private:
    std::vector<Fish*> cells[SIZE][SIZE];
    std::vector<Fish*> temp_cells[SIZE][SIZE];
};

#endif // SEA_H_INCLUDED
