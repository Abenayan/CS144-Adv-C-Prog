#ifndef FISH_H_INCLUDED
#define FISH_H_INCLUDED

class Fish {
public:
    // 1. (a) [1 point]
    // Initialize the private member variables to the values
    // in the comments next to the variables.
    Fish();

    // (b) [2 points]
    // Increment age. Increase size by growth_rate times current size.
    // Then set growth rate to 0.8 of the current growth rate.
    // If age is greater than 3, set alive to false with a probability of 0.8.
    void Grow();

    // (c) [3 points]
    // Reproduce with the probability given by reproduce_probability.
    // If decide to reproduce, return pointer to new Fish.
    // Otherwise, return null pointer.
    Fish* Reproduce();

    // (d) [1 point]
    // Returns true if fish is alive, false otherwise.
    bool IsAlive();

    // (e) [1 point]
    // Print the vital stats (size and age) of the fish.
    void Print();

private:
    float reproduce_probability; // Initialized to 0.4
    float growth_rate; // Initialized to 0.2
    float size; // Initialized to 1
    int age; // Initialized to 0
    bool alive; // Initialized to true
};

#endif // FISH_H_INCLUDED
