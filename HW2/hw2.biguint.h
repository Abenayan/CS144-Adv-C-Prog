#ifndef HW2_BIGUINT_H
#define HW2_BIGUINT_H

#include <iostream>

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
  // 1. (1 point) Initializes the BigUInt to 0.
  BigUInt();

  // 2. (5 points) Initializes the BigUInt to n.
  // Allocate data to an array the number of digits.
  BigUInt(unsigned int n);

  // 3. (1 point) Frees space in data.
  ~BigUInt();

  // 4. (1 point) Print the number represented by this BigUInt.
  void Print();

  // 5. (4 points) Set this BigUInt to original value times 10^p.
  // Allocate space as neccessary.
  void TimesTenPow(unsigned int p);

  // 6. (6 points) Set this BigUInt to original value plus rhs.
  // Allocate space as necessary.
  BigUInt& operator+=(const BigUInt& rhs);

  // 7. (2 points) Print the number represented by this BigUInt.
  friend ostream& operator<<(ostream& os, const BigUInt& b);
};

ostream& operator<<(ostream& os, const BigUInt& b);

#endif  // HW2_BIGUINT_H
