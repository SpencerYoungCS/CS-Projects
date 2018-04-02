#ifndef CH10RATIONAL_H
#define CH10RATIONAL_H

class Rational
{
public:
    Rational();
    Rational(int a);
    Rational(int a, int b);

    int Add(int num);
    int Sub(int num);
    int Mul(int num);
    int Div(int num);
    int Neg(int num);



private:
    int A;
    int B;
};

#endif // CH10RATIONAL_H
