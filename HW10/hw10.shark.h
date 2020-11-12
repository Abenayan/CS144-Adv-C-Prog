#ifndef SHARK_H_INCLUDED
#define SHARK_H_INCLUDED

#include <vector>
#include "hw10.fish.h"

using namespace std;

// (2 points)
// Write a class Shark that inherits from Fish.
// Note that Shark objects are created in Sea::Sea() in sea.cpp.
// In the constructor, set hunger to zero, and set edible to false.

// (3 points)
// Shark class should have these additional private member variables:
//    static const float max_hunger;
//    static float hunger_increment;
//    float hunger;
// In main.cpp, initialize max_hunger to 20.0, and
// initialize hunger_increment to 5.0.

// (3 points)
// Redefine the Grow() function for Shark that:
//   1. If hunger is greater than max_hunger, call Die().
//   2. Increase hunger by hunger_increment.
//   3. Call the regular Fish::Grow() function to grow just like a fish.

// (1 point)
// Redefine the Reproduce() function that is same as the regular Fish::Reproduce()
// except that it should return a Shark rather than a Fish.

// (4 points)
// Write a new member function of the Shark class:
//   void Eat(std::vector<Fish*> fish_in_cell);
// When this function is called, eat as much Fish as necessary to satisfy hunger.
// For example, if the shark's hunger is 7, and there are four fish whose sizes are 2, 4, 2, 5,
// then the first 3 fish will be eaten, and the shark's hunger is set to zero.
// For each fish eaten, call Die() for the fish.
// Note that only edible fish can be eaten. Sharks are not edible.
// Another example, suppose the shark's hunger is 7, and there are two fish whose sizes are 2, 3,
// then both fish would be eaten, and the shark's new hunger value is 7 - 2 - 3 = 5.
// Note that Eat() is called in Sea::SimulateOneStep().

// (2 points)
// In Fish class, change Grow(), Print() and Reproduce() to virtual functions
// and also add Eat() as a virtual function in Fish. Fish::Eat() does nothing.
// so that the following code calls Shark::Print():
//   Fish* fptr = new Shark;
//   fptr->Print();
// This should work for Grow(), Reproduce() and Eat() as well.


class Shark : public Fish {
public:
    Shark();
    void Grow();
    void Print();
    Fish* Reproduce();
    void Eat(std::vector<Fish*> fish_in_cell);
private:
    static const float max_hunger;
    static float hunger_increment;
    float hunger;
};


#endif // SHARK_H_INCLUDED
