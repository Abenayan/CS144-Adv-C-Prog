#include <iostream>
#include <random>
#include "hw7.fish.h"

using namespace std;

Fish::Fish(){
    reproduce_probability = 0.4;
    growth_rate = 0.2;
    size = 1.0;
    age = 0;
    alive = true;
}

void Fish::Grow(){
    age += 1; 
    size += growth_rate * size;
    growth_rate *= 0.8;
    if(age > 3){
        alive = false;
        reproduce_probability = 0.8;
    }
}

Fish* Fish::Reproduce(){
    std::default_random_engine rand_engine;
    std::bernoulli_distribution random_bool_generator(reproduce_probability); 
    bool reproduce = random_bool_generator(rand_engine);
    if(reproduce){
        Fish* temp = new Fish();
        return temp;
    }
    return nullptr;
}

bool Fish::IsAlive(){
    return alive;
}

void Fish::Print(){
    cout << "Age: " << age << ", Size: " << size << endl;
}