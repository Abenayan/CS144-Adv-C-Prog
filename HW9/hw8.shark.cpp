#include <cstdlib>
#include "hw8.shark.h"
#include <iostream>

Shark::Shark():Fish(){
    hunger = 0;
    this->SetEdible(false); 
}

void Shark::Grow(){
    if(hunger > max_hunger){
        this->Die();
    }
    hunger += hunger_increment;
    this->Fish::Grow();
}

Fish* Shark::Reproduce(){
    Fish* fptr = Fish::Reproduce();
    if(fptr != nullptr){
        return new Shark;
    }
    return nullptr;
}

void Shark::Eat(std::vector<Fish*> fish_in_cell){
    bool finished = false;
    for(Fish* fptr : fish_in_cell){
        if(!finished && fptr->IsEdible()){
            hunger -= fptr->GetSize();
            if(hunger<=0){
                hunger = 0;
                finished = true;
            }
        }
    }
}

void Shark::Print(){
    Fish* fptr = new Shark;
    fptr->Print();
}