#include "rational.h"
#include <iostream>

using namespace std;

Rational::Rational()
{
    num = 1;
    deno = 1;
}

Rational::Rational(int number)
{
    num = number;
    deno = 1;
}

Rational::Rational(int number, int denom)
{
    num = number;
    deno = denom;
}

int Rational::getnum()
{
    return num;
}

int Rational::getdeno()
{
    return deno;
}

void Rational::setnum(int NewNum)
{
    num = NewNum;
}

void Rational::setdeno(int NewDeno)
{
    deno = NewDeno;
}

void Rational::Set(int new_num, int new_denom)
{
    setnum(new_num);
    setdeno(new_denom);

}

Rational Rational::Add(Rational B)
{

    num = (num * B.getdeno()) + (B.getnum() * deno);
    deno = (deno * B.getdeno());
    Rational C;
    C.setdeno(deno);
    C.setnum(num);
    return C;
}

Rational Rational::Sub(Rational B)
{
    num = (num * B.getdeno()) - (B.getnum() * deno);
    deno = (deno * B.getdeno());
    Rational C;
    C.setdeno(deno);
    C.setnum(num);
    return C;
}

Rational Rational::Mul(Rational B)
{
    num = num * B.getnum();
    deno = deno * B.getdeno();
    Rational C;
    C.setdeno(deno);
    C.setnum(num);
    return C;

}
Rational Rational::Div(Rational B)
{
    num = num * B.getdeno();
    deno = deno * B.getnum();
    Rational C;
    C.setdeno(deno);
    C.setnum(num);
    return C;
}
Rational Rational::Neg()
{
    num = -num;
    Rational C;
    C.setnum(num);
    return C;
}

bool Rational::Less(Rational B)
{
    if((num*B.getdeno()) < (B.getnum()*deno))
    {
        return true;
    }
    return false;
}

//Operators

Rational operator + (Rational A, Rational B)
{
    int number1 = (A.num * B.deno) + (B.num * A.deno);
    int number2 = (A.deno * B.deno);
    Rational C(number1,number2);
    return C;

}

Rational operator + (int A, Rational B)
{
    int number1 = (A * B.deno) + (B.num);
    int number2 = (B.deno);
    Rational C(number1,number2);
    return C;
}

Rational operator + (Rational B, int A)
{
    int number1 = (A * B.deno) + (B.num);
    int number2 = (B.deno);
    Rational C(number1,number2);
    return C;
}

Rational operator - (Rational A, Rational B)
{
    int number1 = (A.num * B.deno) - (B.num * A.deno);
    int number2 = (A.deno * B.deno);
    Rational C(number1,number2);
    return C;
}

Rational operator - (int A, Rational B)
{
    int number1 = (A * B.deno) - (B.num);
    int number2 = (B.deno);
    Rational C(number1,number2);
    return C;
}

Rational operator - (Rational B, int A)
{
    int number1 =  (B.num)- (A * B.deno);
    int number2 = (B.deno);
    Rational C(number1,number2);
    return C;
}


//cout / cin

ostream& operator << (ostream& out, Rational A) // couts a rational number
{
    return out << A.getnum() << "/" << A.getdeno();
}

istream& operator >> (istream& in, Rational& A)
{
    char slash;
    in >> A.num >> slash >> A.deno;
    return in;
}



//Rational operator++(Rational& R, int)
