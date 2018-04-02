#ifndef TOKEN
#define TOKEN

#include <stack>
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <queue>
#include <sstream>

//-----------------------THIS IS MY NEW FRESH TOKEN CLASS THAT IS EASIER TO HANDLE------------
using namespace std;

class Token{
public:
    Token();
    Token(string item);
    void SetToken(string item);
    string getToken();
    bool isDigit();
    bool NumberChecker();
    ~Token();
private:
    string token;
    bool isNumber;
};

Token::Token(){
}

Token::Token(string item)
{
    token = item;
    isNumber = NumberChecker();
}

void Token::SetToken(string item)
{
    token = item;
}

string Token::getToken()
{
    return token;
}

bool Token::isDigit()
{
    return isNumber;
}

bool Token::NumberChecker(){
    return isdigit(token[0]);
}

Token::~Token()
{

}

#endif // TOKEN
