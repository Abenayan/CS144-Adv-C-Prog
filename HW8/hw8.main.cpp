#include <iostream>
#include "hw8.sea.h"

using namespace std;

float Shark::hunger_increment = 5.0;
const float Shark::max_hunger = 20.0;

int main() {
    int nsharks, nfish;
    Sea S;
    S.PopulationCensus(nsharks, nfish);
    cout << "Init num sharks: " << nsharks << " nfish: " << nfish << endl;

    for (int i = 1; i < 17; i++) {
        S.SimulateOneStep();
        S.PopulationCensus(nsharks, nfish);
        cout << "Step " << i << " num sharks: " << nsharks << " nfish: "
	     << nfish << endl;
    }

    return 0;
}

/*
Sample output:
Init num sharks: 5 nfish: 10
Step 1 num sharks: 4 nfish: 9
Step 2 num sharks: 3 nfish: 7
Step 3 num sharks: 3 nfish: 7
Step 4 num sharks: 1 nfish: 3
Step 5 num sharks: 0 nfish: 1
Step 6 num sharks: 0 nfish: 1
Step 7 num sharks: 0 nfish: 1
Step 8 num sharks: 0 nfish: 2
Step 9 num sharks: 0 nfish: 1
Step 10 num sharks: 0 nfish: 1
Step 11 num sharks: 0 nfish: 1
Step 12 num sharks: 0 nfish: 0
Step 13 num sharks: 0 nfish: 0
Step 14 num sharks: 0 nfish: 0
Step 15 num sharks: 0 nfish: 0
Step 16 num sharks: 0 nfish: 0
*/
