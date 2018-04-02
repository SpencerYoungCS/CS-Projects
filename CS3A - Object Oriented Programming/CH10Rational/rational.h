#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

using namespace std;

class Rational
{
public:
    Rational();
    Rational(int number);
    Rational(int number, int denom);
    Rational Add(Rational B);
    Rational Sub(Rational B);
    Rational Mul(Rational B);
    Rational Div(Rational B);
    Rational Neg();
    bool Less(Rational B);

    //Accessors
    int getnum();
    int getdeno();

    //Mutators
    void setnum(int NewNum);
    void setdeno(int NewDeno);
    void Set(int new_num, int new_denom);

    //Friends AND OPERATORS
    friend Rational operator + (Rational A, Rational B);
    friend Rational operator + (int A, Rational B);
    friend Rational operator + (Rational B, int A);
    friend Rational operator - (Rational A, Rational B);
    friend Rational operator - (int A, Rational B);
    friend Rational operator - (Rational B, int A);
    friend ostream& operator << (ostream& out, Rational A);
    friend istream& operator >> (istream& in, Rational& A);

    
private:

    int num;
    int deno;

};


#endif // RATIONAL_H
