#include <iostream>
#include <cstdlib>
#include "hw8.fish.h"

using namespace std;

Fish::Fish() {
    reproduce_probability = 0.2; // Initialized to 0.2
    growth_rate = 0.2; // Initialized to 0.2
    size = 1; // Initialized to 1
    age = 0; // Initialized to 0
    alive = true; // Initialized to true
    edible = true;
}

// Increment age. Increase size by growth_rate.
// Then set growth rate to 0.8 of the current growth rate.
// If age is greater than 3, set alive to false with a probability of 0.8.
void Fish::Grow() {
    size += growth_rate * size;
    growth_rate *= 0.8;
    age++;
    if (age > 3) {
        int i = rand() % 1000;
        if (i < 800) alive = false;
    }
}

// Reproduce with the probability given by reproduce_probability x (age - 2).
// If decide to reproduce, return pointer to new Fish.
// Otherwise, return null pointer.
Fish* Fish::Reproduce() {
    float threshold = static_cast<float>(age - 2) * reproduce_probability * 1000.0;
    float f = static_cast<float>(rand() % 1000);
    if (f < threshold) {
        return new Fish;
    } else {
        return nullptr;
    }
}

// Print the vital stats of the fish.
void Fish::Print() {
    cout << "Age: " << age << " Size: " << size << endl;
}

void Fish::Die(){
    alive = false;
}

bool Fish::IsEdible(){
    return edible;
}

void Fish::SetEdible(bool e){
    edible = e;
}

float Fish::GetSize(){
    return size;
}

bool Fish::IsAlive(){
    return alive;
}

void Fish::Eat(std::vector<Fish*> fish_in_cell){
    return;
}