#include "hw10.ocean.h"
#include <iostream>
#include <thread>
Ocean::Ocean(){
    Sea start(0, 0, true);
    seas.push_back(&start);
}

void Ocean::SimulateOneStep(){
    vector<thread> threads;
    cout << "PART 1" << endl;
    /*auto f = [&](thread *t){
        threads.push_back(t);
    };
    for(Sea *sptr : seas){
        f(new thread(&Sea::SimulateOneStep, sptr));
    }
    */
    /*for(Sea *sptr : seas){
        thread *worker = new thread{[sptr](){sptr->SimulateOneStep();}};
        threads.push_back(worker);
    }*/


   // for(Sea *sptr : seas){
     //   threads.push_back(new thread(&Sea::SimulateOneStep, sptr));
    //}

    /*for(thread *t : threads){
       t->join();
    }*/


    cout << "PART 2" << endl;
    for(Sea *sptr : seas){
        sptr->SimulateOneStep();
        //thread t(&Sea::SimulateOneStep, *sptr);
        //threads.push_back(move(t));

        /*        threads.push_back(thread([this](Sea *ptr){
                    ptr->SimulateOneStep();
                }, sptr));

        */
    }

    for (auto& t : threads) t.join();
    cout << "PART 3" << endl;
    for (Sea *sptr : seas){
        for(int i = 0; i < SIZE; i++){

            //above
            for(Fish *fptr : sptr->up_buffer[i]){
                if(sptr->above == nullptr){
                    MakeAndConnectSea(sptr->startx - SIZE, sptr->starty);
                }
                sptr->above->temp_cells[SIZE-1][i].push_back(fptr);
            }

            //below
            for(Fish *fptr : sptr->down_buffer[i]){
                if(sptr->below == nullptr){
                    MakeAndConnectSea(sptr->startx + SIZE, sptr->starty);
                }
                sptr->below->temp_cells[0][i].push_back(fptr);
            }

            //left
            for(Fish *fptr : sptr->left_buffer[i]){
                if(sptr->left == nullptr){
                    MakeAndConnectSea(sptr->startx, sptr->starty - SIZE);
                }
                sptr->left->temp_cells[i][SIZE-1].push_back(fptr);
            }

            //right
            for(Fish *fptr : sptr->right_buffer[i]){
                if(sptr->right == nullptr){
                    MakeAndConnectSea(sptr->startx, sptr->starty + SIZE);
                }
                sptr->left->temp_cells[i][0].push_back(fptr);
            }            
        }
    }
    for(Sea *sptr : seas){
        sptr->up_buffer->clear();
        sptr->down_buffer->clear();
        sptr->left_buffer->clear();
        sptr->right_buffer->clear();
    }
}

void Ocean::MakeAndConnectSea(int sx, int sy){
    Sea newSea(sx, sy, false);
    Sea *temp = &newSea;
    cout << "PART 4" << endl;
    for(Sea *sea : seas){
        if(sea->startx + SIZE == sx && sea->starty == sy){
            sea->below = temp;
            temp->above = sea;

        }
        else if(sea->startx - SIZE == sx && sea->starty == sy){

            sea->above = temp;
            temp->below = sea;
            //min_x = sea->startx - SIZE;
        }
        else if(sea->startx == sx && sea->starty - SIZE == sy){
            sea->right = temp;
            temp->left = sea;
        }
        else if(sea->startx == sx && sea->starty + SIZE == sy){
            sea->left = temp;
            temp->right = sea;
        }

        if(sx < min_x){
            min_x = sx;
        }
        if(sx > max_x){
            max_x = sx;
        }
        if(sy < min_y){
            min_y = sy;
        }
        if(sy > min_y){
            max_y = sy;
        }
    }

    cout << "PART 5" << endl;
    seas.push_back(temp);
    if(seas.size() > max_seas)
    {
        //Throw Exception?
        throw "Max sea count reached";
        //return exception;
    }
}

void Ocean::Print(){
    cout << "Min_x: " << min_x << "\nMax_x: " << max_x << "\nMin_y: " << min_y << "\nMax_y: " << max_y << endl;
    for(Sea *sptr : seas){
        sptr->Print();
    }

    /*int amountRows = (min_x * -1) + max_x;
    int amountColumns = (min_y * -1) + max_y;

    int matrix[amountRows][amountColumns];
    for(int x = 0; x <= amountRows; x++){
        for(int y = 0; y <= amountColumns; y++){
            matrix[x][y] = -1;
        }
    }

    int mRow = 0;
    int mColumn = 0;

    for(int x = 0; x <= amountRows; x++){
        for(int y = 0; y <= amountColumns; y++){

            bool exist = false;
            Sea *currentSea;

            for(Sea *sptr : seas){
                if(sptr->startx == x && sptr->starty == y){
                    exist = true;
                    currentSea = sptr;
                }
            }

            if(exist){
                int xRow = 0;
                int yColumn = 0;

                for(int nx = mRow; nx < mRow+SIZE; nx++){
                    for(int ny = mColumn; ny < mColumn+SIZE; ny++){
                        matrix[nx][ny] = currentSea->cells[xRow][yColumn].size();
                        yColumn += 1;
                    }
                    xRow += 1;
                }
            }
        }
    }

    for(int x = 0; x <= amountRows; x++){
        for(int y = 0; y <= amountColumns; y++){

            if(matrix[x][y] == -1){
                cout << "x";
            }
            else{
                cout << matrix[x][y];
            }
        }
    }*/
}

void Ocean::PopulationCensus(int& nshark, int& nfish){
    //nshark = 0;
    //nfish = 0;
    //int tempShark, tempFish;
    vector<thread> threads;
    for(Sea *sptr : seas){
        /*threads.push_back(thread([&, this](Sea *ptr){
            ptr->PopulationCensus(nshark, nfish);
        }, sptr));*/
        Sea s = *sptr;
        //thread t(&Sea::PopulationCensus, ref(*sptr), ref(nshark), ref(nfish));
        /*thread t ([this](Sea *ptr, int nshark, int nfish){
            nshark = 0;
            nfish = 0;
            ptr->PopulationCensus(ref(nshark), ref(nfish));
        }, sptr);*/

        //threads.push_back(move(t));


        //WORKING --------- 
        //thread t(&Sea::PopulationCensus, &s, ref(nshark), ref(nfish));
        sptr->PopulationCensus(nshark, nfish);
        
        /*thread t([this](Sea sptr, int tempShark, int tempFish){
            sptr.PopulationCensus(ref(tempShark), ref(tempFish));
            int a[2];
            a[0] = tempShark;
            a[1] = tempFish;
            return a;
        }, s);*/
        //t.join();
        //threads.push_back(move(t));
    }

    for (auto&& t : threads) t.join();
    
}