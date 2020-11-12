#include "hw7.sea.h"
#include <iostream>
#include <vector>
#include <random>

using namespace std;

Sea::Sea(){
    /*for(int x = 0; x < SIZE; x++){
        for(int y = 0; y < SIZE; y++){
            std::vector<Fish*> temp = temp_cells[x][y];
            std::vector<Fish*> temp2 = cells[x][y];
            for(int i = 0; i < temp.size(); i++){
                temp.push_back(nullptr);
            }
            for(int i = 0; i < temp2.size(); i++){
                temp2.push_back(nullptr);
            }
            //cells[x][y].push_back(nullptr);
            //temp_cells[x][y].push_back(nullptr);
        }
    }*/
    for(int y = 0; y < INIT_NUM_FISH; y++){
        int random = rand() % 100 + 0;
        int random2 = rand() % 100 + 0;
        Fish* temp = new Fish();
        cells[random][random2].push_back(temp);
        //temp_cells[random][random2].push_back(temp);
    }
    
}

/*void Sea::SimulateOneStep(){
    for(int x = 0; x < SIZE; x++){
        for(int y = 0; y < SIZE; y++){
            for(int i = 0; i < cells[x][y].size(); i++){
                Fish* temp_fish = cells[x][y][i];
                if(temp_fish != nullptr){
                    temp_fish->Grow();
                    Fish* new_fish = temp_fish->Reproduce();
                    if(new_fish != nullptr){
                       //cells[x][y].push_back(new_fish); 
                    }
                    //cells[x][y].push_back(new_fish);
                    int random = rand() % 3 + 0;
                    if(random == 0){
                        if(y-1 >= 0){
                            temp_cells[x][y-1].push_back(temp_fish);
                        }
                    }
                    else if (random == 1){
                        if(y+1 < SIZE){
                            temp_cells[x][y+1].push_back(temp_fish);

                        }
                    }
                    else if(random == 2){
                        if(x+1 < SIZE){
                            temp_cells[x+1][y].push_back(temp_fish);
 
                        }
                    }
                    else if(random == 3){
                        if(x-1 >= 0){
                            temp_cells[x-1][y].push_back(temp_fish);
                        }
                    }
                    cells[x][y][i] = nullptr;
                    //Fish* new_fish = temp_fish->Reproduce();

                }
            }
        }
    }
    for(int x = 0; x < SIZE; x++){
        for(int y = 0; y < SIZE; y++){
            for(int i = 0; i < temp_cells[x][y].size(); i++){
                Fish* left = temp_cells[x][y][i];
                Fish* right = cells[x][y][i];
                if(left != nullptr){
                    right = left;
                    left = nullptr;
                }

            }
        }
    }
}*/

void Sea::SimulateOneStep(){
    for(int x = 0; x < SIZE; x++){
        for(int y = 0; y < SIZE; y++){
            std::vector<Fish*> temp = cells[x][y];
            //std::vector<Fish*> original = cells[x][y];
            for(int i = 0; i < temp.size(); i++){
                Fish* temp_fish = temp[i];
                if(temp_fish != nullptr){
                    temp_fish->Grow();
                    Fish* newFish = temp_fish->Reproduce();
                    if(newFish != nullptr){
                        //std::default_random_engine rand_engine;
                        //std::bernoulli_distribution random_bool_generator(0.5); 
                        //bool leftorright = random_bool_generator(rand_engine);
                        //left if true, right if false
                        int random = rand() % 3 + 0;
                        if(random == 0){
                            if(y-1 >= 0){
                                temp_cells[x][y-1].push_back(newFish); 
                            }
                            else{
                                delete newFish;
                            }
                        }
                        else if (random == 1){
                            if(y+1 < SIZE){
                                temp_cells[x][y+1].push_back(newFish); 
                            }
                            else{
                                delete newFish;
                            }
                        }
                        else if(random == 2){
                            if(x+1 < SIZE){
                                temp_cells[x+1][y].push_back(newFish); 
                            }
                            else{
                                delete newFish;
                            }
                        }
                        else if(random == 3){
                            if(x-1 >= 0){
                                temp_cells[x-1][y].push_back(newFish); 
                            }
                            else{
                                delete newFish;
                            }
                        }
                    }
                }
                if(!temp_fish->IsAlive()){
                    temp.erase(temp.begin()+i);
                }
            }
        }
    }
    /*for(int x = 0; x < SIZE; x++){
        for(int y = 0; y < SIZE; y++){
            std::vector<Fish*> temp = temp_cells[x][y];
            std::vector<Fish*> main = cells[x][y];
            for(int i = 0; i < temp.size(); i ++){
                if(temp[i] != nullptr){
                    if(main[i] == nullptr){
                        //main[i] = temp[i];
                    }
                }
                //temp.erase(temp.begin()+i);
                //delete temp[i];
            }
        }
    }*/
}

void Sea::Print(){
    for(int x = 0; x < SIZE; x++){
        for(int y = 0; y < SIZE; y++){
            std::vector<Fish*> temp = cells[x][y];
            for(int i = 0; i < temp.size(); i++){
                Fish* temp_fish = temp[i];
                if(temp_fish != nullptr){
                    cout << x << ", " << y << endl;
                    temp_fish->Print();
                }
            }
        }
    }
}
