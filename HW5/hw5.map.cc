// You can only include the following libraries:
// iostream, unordered_map, fstream, algorithm, vector
#include<unordered_map>
#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

// You may write helper comparator functions here.
typedef pair<string,double> salespair;

// Do not add any member functions or variables.
class Restaurant {
private:  
  unordered_map<string, double> sales;
public:
  Restaurant() { };

  // 1. (10 points)
  // Read the given text file. Each line in the input file
  // is a food name and amount of the sale (including $ sign).
  // Food name and amount are separated by space.
  // Example input file is hw5.input.txt.
  // Read the input file and keep one entry per food item in the member
  // variable sales. The key is the food name, and the value is to total
  // value of sales.
  void ReadFile(string fname) {
    //Reading from file, and creates key, val pairs of food and price, adds to sales
    ifstream myFile;
    myFile.open(fname);
    string key;
    double value;
    unordered_map<string,double>::iterator it;
    if(!myFile){
      cout << "error";
      exit(1);
    }
    while(myFile >> key){
      it = sales.find(key);
      string temp;
      if(myFile >> temp){
        temp.erase(0, 1);
        value = stod(temp);
        if (it != sales.end()){
          it->second += value;
        }
        else{
          sales[key] = value;
        }
      }
    }
    myFile.close();
  };

  // 2. (5 points)
  // Print the total sales by name of the food item, in alphabetical order.
  // First print "Total by name".
  // Then for each food item, print one line. The line contains the food name,
  // space, and then the total value of sales.
  // Hint: Transfer from sales to vector, and sort vector.
  void PrintByName() {
    //Copies to vector, sorts vector, using elemtn in vector as key to find value, prints
    vector<string> temp;
    unordered_map<string,double>::iterator finder;
    for(unordered_map<string, double>::iterator it = sales.begin(); it != sales.end(); ++it){
      temp.push_back(it->first);
    }
    sort(temp.begin(), temp.end());
    for(string i : temp){
      finder = sales.find(i);
      cout << i << " $"<< finder->second << endl;
    }

  };

  // 3. (5 points)
  // Print the total sales in order of total sales amount.
  // First print "Total by amount".
  // Then for each food item, print one line. The line contains the food name,
  // space, and then the total value of sales.
  void PrintByAmount() {
    //Create a empty vector of pair, and copies over from sales, the sroting the vector in descending order, prints
	  vector<salespair> temp;
    copy(sales.begin(), sales.end(), back_inserter<vector<salespair> >(temp));
    sort(temp.begin(), temp.end(), [] (const salespair& l, const salespair& r){
      if(l.second != r.second){
        return l.second > r.second;
      }
      return l.first > r. first;
    });
    for(salespair i: temp) {
		  cout << i.first << " $" << i.second << endl;
	  }
  };
};

// Do not change main() function.
int main() {
  Restaurant R;
  R.ReadFile("hw5.input.txt");
  R.PrintByName();
  cout << endl;
  R.PrintByAmount();
  return 0;
}

/*
Sample output:

Total by name:
Chips $70.45
Cookie $19.28
Fries $3.99
Hamburger $112.14
Hotdog $20.9
Pizza $309.48
Sandwich $54.82
Soup $105.15
Taco $62.09

Total by amount:
Pizza $309.48
Hamburger $112.14
Soup $105.15
Chips $70.45
Taco $62.09
Sandwich $54.82
Hotdog $20.9
Cookie $19.28
Fries $3.99
*/
