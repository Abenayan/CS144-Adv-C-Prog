#include <iostream>

using namespace std;

class Rational{
  //Private member variables
  private:
    int numerator;
    int denominator;

  public:
  //Constructor without paramteres
    Rational(){
      numerator = 0;
      denominator = 1;
    }
    //Constructor with parameters
    Rational(int a, int b){
      numerator = a;
      denominator = b;
    }

    //Gets numerator
    int getNumerator() const{
      return numerator;
    }
    
    //Gets denominator
    int getDenominator() const{
      return denominator;
    }

    //Sets numerator
    void setNumerator(int a){
      this->numerator = a;
    }

    //Sets denominator
    void setDenominator(int a){
      if(a != 0){
          this->denominator = a;
      }
    }

    //Prints out in numerator and denominator in real number form
    void Print(){
      cout << numerator << "/" << denominator << endl;
    }

    //Reducec numerator and denominator to its lowest fraction
    void Reduce(){
      for (int i = this->numerator*this->denominator;  i > 1; i--){
        if(this->numerator % i == 0 && this->denominator % i == 0){
          this->numerator /= i;
          this->denominator /= i;
        }
      }
    }

    //Overridden operaotr += for Rational object
    void operator += (const Rational &rhs){
      this->numerator = this->numerator * rhs.denominator + this->denominator * rhs.numerator;
      this->denominator = this->denominator * rhs.denominator;
    }
};

//Overridden operaotr * for Rational object
Rational operator *(const Rational &lhs, const Rational &rhs){
  Rational dummy;
  dummy.setDenominator(lhs.getDenominator() * rhs.getDenominator());
  dummy.setNumerator(lhs.getNumerator() * rhs.getNumerator());
  return dummy;
};

//Overridden operaotr + for Rational object
Rational operator +(const Rational &lhs, const Rational &rhs){
  Rational dummy;
  dummy.setDenominator(lhs.getDenominator() * rhs.getDenominator());
  dummy.setNumerator(lhs.getNumerator() * rhs.getDenominator() + lhs.getDenominator() * rhs.getNumerator());
  return dummy;
}


//Overridden operaotr == for Rational object
bool operator ==(const Rational &lhs, const Rational &rhs){
  Rational left = lhs;
  Rational right = rhs;
  left.Reduce();
  right.Reduce();
  return left.getDenominator() == right.getDenominator() && left.getNumerator() == right.getNumerator();
}

int main() {
  Rational r1;
  Rational r2(12,36);

  r1.Print();
  r2.Print();

  r1.Reduce();
  r2.Reduce();
  
  r1.Print();
  r2.Print();

  Rational r3(1,2);
  Rational r4(2,3);
  r4 += r3;
  r4.Print();

  Rational r5(3,8);
  Rational r6(2,5);
  Rational r7;
  r7 = r5 + r6;
  r7.Print();
  
  r7.Reduce();
  r7.Print();

  Rational r8;
  r8 = r5 * r6;
  r8.Print();

  r8.Reduce();
  r8.Print();
  
  Rational r9(36, 12);
  Rational r10(12, 4);

  if (r9 == r10) {
    cout << "equal" << endl;
  } else {
    cout << "not equal" << endl;
  }

  return 0;
}
/*
Results
0/1
12/36
0/1
1/3
7/6
31/40
31/40
6/40
3/20
equal
*/

  
