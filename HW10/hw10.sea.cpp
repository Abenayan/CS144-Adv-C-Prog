#include <iostream>
#include <cstdlib>
#include "hw10.sea.h"

using namespace std;

Sea::Sea(int sx, int sy, bool populate) : startx(sx), starty(sy)
{
  above = below = left = right = nullptr;
  if (populate)
  {
    for (int i = 0; i < INIT_NUM_FISH; i++)
    {
      Fish *fptr = new Fish;
      int x = rand() % SIZE;
      int y = rand() % SIZE;
      cells[x][y].push_back(fptr);
    }
    for (int i = 0; i < INIT_NUM_SHARK; i++)
    {
      Fish *fptr = new Shark;
      int x = rand() % SIZE;
      int y = rand() % SIZE;
      cells[x][y].push_back(fptr);
    }
  }
}

void Sea::SimulateOneStep()
{
  
  //Maybe clear buffers here as well.
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      temp_cells[i][j].clear();
    }
  }
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      vector<Fish *> to_delete;
      for (Fish *fptr : cells[i][j])
      {
        fptr->Grow();
        if (!fptr->IsAlive())
        {
          to_delete.push_back(fptr);
          continue;
        }
        fptr->Eat(cells[i][j]);
        Fish *baby_fish = fptr->Reproduce();
        if (baby_fish != nullptr)
        {
          temp_cells[i][j].push_back(baby_fish);
        }
        int ni = i;
        int nj = j;
        int move_dir = rand() % 4;
        switch (move_dir)
        {
        case 0:

          ni++;
          break;
        case 1:
          ni--;
          break;
        case 2:
          nj++;
          break;
        case 3:
          nj--;
          break;
        }

        if ((ni < 0) || (ni >= SIZE) ||
            (nj < 0) || (nj >= SIZE))
        {
          to_delete.push_back(fptr);
        }

        if (ni < 0)
        {
          up_buffer->push_back(fptr);
        }
        else if (ni >= SIZE)
        {
          down_buffer->push_back(fptr);
        }
        else if (nj < 0)
        {
          left_buffer->push_back(fptr);
        }
        else if (nj >= SIZE)
        {
          right_buffer->push_back(fptr);
        }
        else
        {
          temp_cells[ni][nj].push_back(fptr);
        }
      }
      for (Fish *fptr : to_delete)
      {
        delete fptr;
      }
    }
  }

  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      cells[i][j].clear();
      cells[i][j] = temp_cells[i][j];
    }
  }
}

// Note: This function has been changed from HW 8.
// For each cell print the number of fish in the cell.
void Sea::Print()
{
  cout << "startx: " << startx << endl;
  cout << "starty: " << starty << endl;

  for (int j = 0; j < SIZE; j++)
  {
    for (int i = 0; i < SIZE; i++)
    {
      cout << cells[i][j].size();
    }
    cout << endl;
  }
  cout << endl;
}

void Sea::PopulationCensus(int &nshark, int &nfish)
{
  //nshark = 0;
  //nfish = 0;
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      for (Fish *fptr : cells[i][j])
      {
        if (fptr->IsEdible() && fptr->IsAlive())
        {
          nfish++;
        }
        else if (!fptr->IsEdible())
        {
          nshark++;
        }
      }
    }
  }
}
