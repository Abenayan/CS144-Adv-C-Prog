#include <iostream>
#include "hw10.ocean.h"

using namespace std;

const float Shark::max_hunger = 20.0;
float Shark::hunger_increment = 5.0;
int Ocean::min_x = 0;
int Ocean::max_x = 0;
int Ocean::min_y = 0;
int Ocean::max_y = 0;
const int Ocean::max_seas = 12;

// Modify this code so that you can catch exception thrown by SimulateOneStep.

int main() {
  int nsharks, nfish;
  Ocean ocean;
  ocean.PopulationCensus(nsharks, nfish);
  cout << "Init num sharks: " << nsharks << " nfish: " << nfish << endl;
  ocean.Print();
  
  for (int i = 1; i < 25; i++) {
    try{
      ocean.SimulateOneStep();
    }
    catch(const char* error){
      cout << error << endl;
    }
    ocean.PopulationCensus(nsharks, nfish);
    cout << "Step " << i << " num sharks: " << nsharks << " nfish: "
	 << nfish << endl;
    ocean.Print();
  }

  cout << "done" << endl;
  
  return 0;
}
