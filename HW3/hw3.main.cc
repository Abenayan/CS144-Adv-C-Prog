#include <iostream>
#include "hw3.biguint.h"

using namespace std;

void func(BigUInt b) {
  b.SetDigit(3, 5);
  b.SetDigit(4, 7);
  cout << b << endl;
}


int main() {

  BigUInt b1(88408721);
  func(b1);
  cout << b1 << endl;

  string s = b1.ToString();
  cout << s << endl;

  BigUInt b2(872);
  b2 += 134908571;
  cout << b2 << endl;

  BigUInt b3(645050);
  BigUInt b4(10050385);
  b4 = b3;
  b4.SetDigit(0, 9);
  cout << b3 << " " << b4 << endl;

  BigUInt b5(3459950);
  BigUInt b6(8385);
  if (b5 > b6) cout << "5 greater" << endl;  
  if (b6 > b5) cout << "6 greater" << endl;
  BigUInt b7(3453450);
  BigUInt b8(3458385);
  if (b7 > b8) cout << "7 greater" << endl;
  if (b8 > b7) cout << "8 greater" << endl;
  BigUInt b10(3459950);
  BigUInt b11(3459950);
  if (b10 > b11) cout << "10 greater" << endl;
  if (b11 > b10) cout << "11 greater" << endl;

  BigUInt b12(99832395);
  
  cout << b12 << endl;

  b12.TimesTenPow(7);
  
  cout << b12 << endl;

  BigUInt b13(10);
  b13 = b12 + 170814972;
  cout << b13 << endl;
  
  return 0;
}
/*
Result:
88475721
88408721
88408721
134909443
645050 645059
5 greater
8 greater
99832395
998323950000000
998324120814972
*/

