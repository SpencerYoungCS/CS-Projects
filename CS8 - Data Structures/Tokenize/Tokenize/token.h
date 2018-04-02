#ifndef TOKEN
#define TOKEN
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
class Token{
public:
    Token();
    Token(string s, int type);
    Token(char ch, int type);
    friend ostream& operator<<(ostream& outs, Token& t);
    int Type();
    //    string& getstring();
    string& TokenString();

private:
    string token;
    int tokentype;
};

Token::Token(){
}

Token::Token(string s, int type){
    token = s;
    tokentype = type;
}

Token::Token(char ch, int type)
{
}

int Token::Type(){
    string ALPHABETIC = "abcdefghijklmnopqrstuvwxyzABCDEFHIJKLMNOPQRSTUVWXYZ";
    string NUMERICAL = "0123456789";
    string PUNCTUATION = ";:'!@#$%^&*-_\.,><?/~`";
    string WHITE_SPACE = " ";
    string MATCHED_PAIRS = "[](){}";
    if (token.find_first_of(ALPHABETIC) == 0)
        return 1;
    if (token.find_first_of(NUMERICAL) == 0)
        return 2;
    if (token.find_first_of(PUNCTUATION) == 0)
        return 3;
    if (token.find_first_of(WHITE_SPACE,0) == 0)
        return 4;
    if (token.find_first_of(MATCHED_PAIRS,0) == 0)
        return 5;
}

//string &Token::getstring()
//{
//    return token;
//}

string &Token::TokenString(){
    return token;
}

ostream& operator<<(ostream& outs, Token &t)
{
    outs << "[" << t.TokenString();
//         << "] " << t.gettype();
    return outs;
}

#endif // TOKEN
