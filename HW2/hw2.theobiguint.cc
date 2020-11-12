#include "hw2.biguint.h"

// Initializes the BigUInt to 0.
BigUInt::BigUInt(){
  length = 1; 
  unsigned char a[1] = {'0'}; 
  data = a; 
}
// Initializes the BigUInt to n. 
BigUInt::BigUInt(unsigned int n){
  length = std::to_string(n).length();
  char resultArray[length];
  data = new unsigned char[length];
  sprintf(resultArray, "%d", n);
  int count = 0; 
  for(int i = length-1; i > -1; i--){
      if(count <= length){
          data[count] = resultArray[i];
      }
      count++; 
  }
}
// Prints the number represented by this BigUInt.
void BigUInt::Print(){
  for(int i = length-1; i >= 0; i--){
     cout << data[i];
  }
  cout << "\n";
}
// Set this BigUInt to original value times 10^p.
void BigUInt :: TimesTenPow(unsigned int p){
    this -> length += p;
    unsigned char* tempPtr = data; 
    data  = new unsigned char[length];
    for(int i=0; i<p; i++) {
        data [i] = '0';
    }
    int count = 0; 
    for(int i = p; i < length; i++){
        data[i] = tempPtr[count++];
    }
}
// Print the number represented by this BigUInt.
ostream& operator <<(ostream&os, const BigUInt& b){
    for(int i = b.length; i >= 0; i--){
    os << b.data[i]; 
  }
  cout << "\n";
  return os; 
}
// Frees space in data.
BigUInt::~BigUInt(){
    delete[] data;
}


BigUInt& BigUInt::operator+=(const BigUInt& rhs){
    unsigned char* biggest;
    unsigned char* smallest; 
    int rest = 0; 
    int carry = 0; 
    int counter = 0; 
    int result = 0; 
    int smallestL = 0;
    int biggestL = 0; 

    if(length >= rhs.length){
        biggest = data; 
        smallest = rhs.data;
        smallestL = rhs.length;
        biggestL = length;
    }
    else{
        biggest = rhs.data; 
        smallest = data; 
        smallestL = length; 
        biggestL = rhs.length; 
    }
    while(counter <= smallestL-1){
        result = int(biggest[counter]) - 48 + int(smallest[counter]) - 48 + carry; 
        if(result >= 10){
            rest = result - 10; 
            carry = 1; 
            biggest[counter] = rest + '0'; 
        }
        else{
            biggest[counter] = result + '0'; 
            carry = 0; 
        }
        counter++; 
    }
   
    while(counter <= biggestL-1 && biggestL != smallestL){
        result = int(biggest[counter]) - 48 + carry; 
        if(result >= 10){
            rest = result - 10; 
            carry = 1; 
            biggest[counter] = rest + '0'; 
        }
        else{
            biggest[counter] = result + '0'; 
            carry = 0; 
        }
        counter++; 
    }
    if(carry == 1){
        unsigned char* tempArray = new unsigned char[counter+1];
        for(int i = 0; i < counter; i++){
            tempArray[i] = biggest[i];
        }
        tempArray[counter] = 1 + '0';
        biggest = tempArray;
        length += 1; 
    }
    data = biggest;
    return *this;
}
    

