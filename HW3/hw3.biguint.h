#ifndef HW3_BIGUINT_H
#define HW3_BIGUINT_H

#include <iostream>
#include <string>

using namespace std;

class BigUInt {
 private:
  // Pointer to array. Each element of array contains a digit.
  // Array length is equal to the number of digits of the BigUInt.
  // data[0] contains the least significant digit.
  // For example, if the BigUInt represents the number 385,
  // then data[0] is 5, data[1] is 8, data[2] is 3, and length is 3.
  unsigned char* data;
  // The length of the array data.
  int length;
 public:
  BigUInt();
  BigUInt(unsigned int n);
  ~BigUInt();
  void Print();
  void TimesTenPow(unsigned int p);
  BigUInt& operator+=(const BigUInt& rhs);
  friend ostream& operator<<(ostream& os, const BigUInt& b);

  // (a) (2 points) Write copy constructor such that this->data is
  // pointing to different location as b.data.
  BigUInt(const BigUInt& b);

  // (b) (2 points) Write assignment operator such that this->data is
  // pointing to different location as b.data.
  BigUInt& operator=(const BigUInt& b);

  // (c) (3 points) Write the += operator such that new value is equal
  // to old value + i.
  BigUInt& operator+=(unsigned int i);

  // (d) (2 points) Implement SetDigit. This function sets the digit at
  // position i. It is set to d. Check that the input i is valid.
  // Check also that the input d is valid. If either input is invalid,
  // this function returns without doing anything.
  void SetDigit(int i, int d);

  // (e) (3 points) Return a string representing this unsigned integer.
  // For example, if the integer is 4892, then return a string "4892".
  string ToString();

  friend bool operator>(const BigUInt& lhs, const BigUInt& rhs);
};

ostream& operator<<(ostream& os, const BigUInt& b);

// (f) (4 points) Non-member friend function. Returns true of the value of
// lhs is greater than rhs, returns false otherwise.
bool operator>(const BigUInt& lhs, const BigUInt& rhs);


// (g) (4 points) Write a non-member function + that takes a BigUInt and an
// unsigned int, and returns that BigUInt that represents their sum.
BigUInt operator+(const BigUInt& b, unsigned int i);


#endif  // HW3_BIGUINT_H
