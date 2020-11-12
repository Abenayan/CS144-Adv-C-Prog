#ifndef OCEAN_H
#define OCEAN_H

#include <vector>
#include "hw10.sea.h"

using namespace std;

class Ocean {
 public:
  // 2. (1 point)
  // Start with one Sea with starting coordinates (0, 0).
  // Populate this Sea with some fish.
  // Assume top left corner is (0, 0). The y-coordinate increases downwards.
  Ocean();

  // 3a. (6 points)
  // First call SimulateOneStep() for all seas in the ocean.
  // Then, if fish or shark moves outside of a sea, move into adjacent sea.
  // If adjacent sea doesn't exist, make a new sea. Add sea to seas.
  // Also make sure you set the sea's member variables (above, below etc.).
  // Note: Sea above has smaller y-coordinate. y-coordinate is in cells[y][].
  //       The y-coordinate is the row number.

  // b. (2 points)
  // Throw an exception when number of seas is greater than max_seas.
  // Make sure you catch the exception in the main() function.

  // c. (2 points)
  // Make threads to run Sea::SimulateOneStep() in parallel.
  // Use lambda expression.
  // Make sure no race conditions.
  // To use member variables in lambda expression, capture this.
  void SimulateOneStep();
  // helper function
  void MakeAndConnectSea(int sx, int sy);

  // 4. (4 points)
  // First, print the min and max x and y coordinates of the ocean.
  // Then, print the matrix of the number of fish in each cell.
  // If no sea exists, then print x for all the cells in the sea.
  // If greater than 9 fish in the cell, print 'M'.
  // Top left is (minx, miny).
  void Print();

  // 5a. (1 point)
  // Find total number of fish and sharks in all seas.
  // b. (2 points)
  // Make threads to run in parallel. Make sure no race conditions.
  // Use lambda expression.
  // To use member variables in lambda expression, capture this.
  void PopulationCensus(int& nshark, int& nfish);
 private:

  // Note: Sea definition has been modified to add member variables for
  // starting coordinates.
  vector<Sea*> seas;

  static int min_x;
  static int max_x;
  static int min_y;
  static int max_y;
  static const int max_seas;
};

#endif
