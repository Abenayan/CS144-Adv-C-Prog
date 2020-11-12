#ifndef SEA_H_INCLUDED
#define SEA_H_INCLUDED

#include <vector>
#include "hw10.shark.h"

#define SIZE 8
#define INIT_NUM_FISH 50
#define INIT_NUM_SHARK 0

class Sea {
public:
  // Note: The constructor has changed.
  // sx and sy are the coordinates of the top left cell of this sea.
  // populate: If true, populate this Sea with initial fish and shark.
  //           Else, make an empty Sea.
  //           Populate should be true for the first Sea in the Ocean.
  //           New seas due to fish moving should be empty initially.
  Sea(int sx, int sy, bool populate);

  // 1. (2 points) Change this function so that when a fish (or a shark)
  // moves out of the sea, put it into a buffer cell (for example up_buffer).
  // The buffers should be cleared before each call to SimulateOneStep.
  // The buffers will be used by Ocean to move fish to adjacent seas.
  void SimulateOneStep();
  void Print();
  void PopulationCensus(int& nshark, int& nfish);
private:
  std::vector<Fish*> cells[SIZE][SIZE];
  std::vector<Fish*> temp_cells[SIZE][SIZE];

  // Buffers to store fish that move out of the sea for each iteration.
  std::vector<Fish*> up_buffer[SIZE];
  std::vector<Fish*> down_buffer[SIZE];
  std::vector<Fish*> left_buffer[SIZE];
  std::vector<Fish*> right_buffer[SIZE];

  // Top left corner
  int startx;
  int starty;

  // Pointers to adjacent seas
  Sea* above;
  Sea* below;
  Sea* left;
  Sea* right;

  friend class Ocean;
};

#endif // SEA_H_INCLUDED
