#ifndef STOKENIZE
#define STOKENIZE
#include <vector>
#include "token.h"

class STokenize{
public:
    STokenize();
    STokenize(const string newstring);
    //    friend STokenize& operator >> (STokenize);
    int GetTokenType(string ch, int position);
    string GetTokenString(string ch, int pos);
    string NextString();
    Token GetToken(string line);
    bool Fail();
    bool More(string line);
    int NextPos();
private:
    string str;
    int position = 0;
    string file;
    vector<string> charList;
    string ALPHABETIC = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string NUMERICAL = "0123456789";
    string PUNCTUATION = ";:'!@#$%^&*-_\.,><?/~`\"";
    string WHITE_SPACE = " ";
    string MATCHED_PAIRS = "[](){}";
    string EMPTY = "\n";
    string SPECIAL = "é";
};


STokenize::STokenize()
{
}

STokenize::STokenize(const string newstring)
{
    cout << "initialized: " << endl;
    str = newstring;
}

int STokenize::GetTokenType(string ch, int position)
{
    if (ch.find_first_of(ALPHABETIC,position) == position)
        return 1;
    else if (ch.find_first_of(NUMERICAL,position) == position)
        return 2;
    else if (ch.find_first_of(PUNCTUATION,position) == position)
        return 3;
    else if (ch.find_first_of(WHITE_SPACE,position) == position)
        return 4;
    else if (ch.find_first_of(MATCHED_PAIRS, position) == position)
        return 5;
    else if (ch.find_first_of(EMPTY, position) == position)
        return 6;
    else if (ch.find_first_of(SPECIAL, position) == position)
        return 7;
    //7 would be the special symbols
}

string STokenize::GetTokenString(string ch, int pos)
{
    int posEnd;
    int length;

    char temp[100];
    string temp2;

    switch(GetTokenType(ch,pos)){
    case 1:
        posEnd = ch.find_first_not_of(ALPHABETIC,pos);
        length = posEnd - pos;
        ch.copy(temp,length,pos);
        temp[length] = '\0';
        temp2 = temp;
        return temp2;
        break;
    case 2:
        posEnd = ch.find_first_not_of(NUMERICAL,pos);
        length = posEnd - pos;
        ch.copy(temp,length,pos);
        temp[length] = '\0';
        temp2 = temp;
        return temp2;
        break;
    case 3:
        posEnd = ch.find_first_not_of(PUNCTUATION,pos);
        length = posEnd - pos;
        ch.copy(temp,length,pos);
        temp[length] = '\0';
        temp2 = temp;
        return temp2;
        break;
    case 4:
        posEnd = ch.find_first_not_of(WHITE_SPACE,pos);
        length = posEnd - pos;
        ch.copy(temp,length,pos);
        temp[length] = '\0';
        temp2 = temp;
        return temp2;
        break;
    case 5:
        posEnd = ch.find_first_not_of(MATCHED_PAIRS,pos);
        length = posEnd - pos;
        ch.copy(temp,length,pos);
        temp[length] = '\0';
        temp2 = temp;
        return temp2;
        break;
    case 6:
        posEnd = ch.find_first_not_of(EMPTY,pos);
        length = posEnd - pos;
        ch.copy(temp,length,pos);
        temp[length] = '\0';
        temp2 = temp;
        return temp2;
        break;
    case 7:
        posEnd = ch.find_first_not_of(SPECIAL,pos);
        length = posEnd - pos;
        ch.copy(temp,length,pos);
        temp[length] = '\0';
        temp2 = temp;
        return temp2;
    default:
        cout << "Error, GetTokenType Not Found" << endl;

        break;
        return ch;
    }
    delete temp;
}

Token STokenize::GetToken(string line){


    file = line;
         str = GetTokenString(file,position);
//         cout << str;
    Token token(str,GetTokenType(file,position));
    return token;

//         token.TokenString(str);

}

bool STokenize::More(string line)
{
        position = position + GetTokenString(line,position).length();
        if(position <=line.length()-2)
            return true;
        else
            return false;
}

int STokenize::NextPos()
{
    position =  position + GetTokenString(str,position).length();

}

#endif // STOKENIZE
