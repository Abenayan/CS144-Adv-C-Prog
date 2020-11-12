#ifndef SEA_H_INCLUDED
#define SEA_H_INCLUDED

#include <vector>
#include "hw7.fish.h"

#define SIZE 100
#define INIT_NUM_FISH 8

class Sea {
public:
    // 2. (a) [2 points]
    // Initialize INIT_NUM_FISH number of fish in random cells.
    Sea();

    // (b) [8 points]
    // For each fish in the sea, call Grow(), then call Reproduce() even if
    // after Grow() fish is no longer alive.
    // If Reproduce() returns a new fish, add it to the vector for that cell.
    // Then move the fish to an adjacent cell (no diagonal) at random.
    // Note that in the same simulation step, this same fish should not be
    // processed again.
    // If the random direction chosen goes outside the sea, then remove this
    // fish from the sea, and deallocate memory.
    // If fish is no longer alive, remove from vector, and deallocate memory.
    void SimulateOneStep();

    // (c) [2 points]
    // For each cell print all the fish in the cell.
    void Print();
private:
    std::vector<Fish*> cells[SIZE][SIZE];
    std::vector<Fish*> temp_cells[SIZE][SIZE]; // temp for SimulateOneStep()
};

#endif // SEA_H_INCLUDED
