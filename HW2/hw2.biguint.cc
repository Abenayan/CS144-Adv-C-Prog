//Includes template for class and methods
#include "hw2.biguint.h"


//Default construcotr, initlized to 0
BigUInt::BigUInt(){
    data = nullptr;
    length = 1;
    data = new unsigned char[length];
    data[0] = '0';
}

//Construcotr initlizes depending on n
BigUInt::BigUInt(unsigned int n){
    length = to_string(n).length();
    char temp[length];
    data = new unsigned char[length];
    sprintf(temp, "%d", n);
    int counter = 0;
    for (int i = length-1; i > -1; i--){
        if(counter <= length){
            data[counter] = temp[i];
        }
        counter += 1;
    }
} 

//Frees allocated space to pointer
BigUInt::~BigUInt(){
    delete [] data;
}

//Prints out current repsented number in BigUInt
void BigUInt::Print(){
    for (int i = length-1; i > -1; i--){
        cout << data[i];
    }
    cout << "\n";
}

//Takes the current BigUInt to the power of given p
void BigUInt::TimesTenPow(unsigned int p){
    length += p;
    unsigned char* temp = data;
    data = new unsigned char[length];
    for(int i = 0; i < p; i++){
        data[i] = '0';
    }
    int counter = 0; 
    for(int i = p; i < length; i++){
        data[i] = temp[counter++];
    }
    delete[] temp;
} 

//Allows for BigUInt to be used with operator +=
BigUInt& BigUInt::operator+=(const BigUInt& rhs){
     int largestSize = 0;
     int flag = -1;
     unsigned char* tempptr;
     if(length >= rhs.length){
         largestSize = length + 1;
         flag = 0;
         tempptr = data;
     }
     else{
         largestSize = rhs.length + 1;
         flag = 1;
         tempptr = rhs.data;
     }
     data = new unsigned char[largestSize];
     char temp[largestSize];
     if(flag == 0){
        for(int i = 0; i < rhs.length; i++){
            temp[i] = rhs.data[i];
        }
        for(int i = rhs.length; i <= largestSize; i++){
            temp[i] = '0';
        }
        
     }
     else{
        for(int i = 0; i < length; i++){
            temp[i] = data[i];
        }
        for(int i = length; i <= largestSize; i++){
            temp[i] = '0';
        }
     }
     int carry = 0, sum = 0;
     int tempArray[largestSize];
     for(int i = 0; i < largestSize-1; i++){
        int templhs = int(tempptr[i]) - 48;
        int temprhs = int(temp[i]) - 48;
        sum = carry + templhs + temprhs;
        if(sum >= 10){
            carry = 1;
            sum = sum - 10;
        }
        else{
            carry = 0;
        }            
        tempArray[i] = sum;
    }
    if(carry != 0){
        tempArray[largestSize-1] = carry;
    }
    else{
        tempArray[largestSize-1] = '\0';
    }
    for(int i = 0; i <= largestSize-1; i++){
        data[i] = tempArray[i]+ '0';
    }
    if(data[largestSize - 1] == '0'){
        largestSize = largestSize-1;
    }
    length = largestSize;
    delete[] tempptr;
    return *this;
 }


//Allows operator << to be used with BigUInt
ostream& operator<<(ostream& os, const BigUInt& b){
    for(int i = b.length-1; i > -1; i--){
        os << b.data[i]; 
    }
    os << "\n";
    return os; 
}