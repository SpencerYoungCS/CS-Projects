#ifndef TOKENIZER
#define TOKENIZER
#include "token.h"

//-------------------------THIS WILL MAKE A LIST OF TOKENS----------------------

class Tokenizer{
public:
    Tokenizer();
    Tokenizer(string item);
    void printVector();
    vector<Token> getlist();
    int getsize();
private:
    vector<Token> list;
};

Tokenizer::Tokenizer()
{
}

Tokenizer::Tokenizer(string item){

    //takes in the whole equation.
    //breaks it apart and turns into vectors
    //puts into vector
    for(int pos = 0; pos < item.length();){
        string holdstring;
        while(isdigit(item[pos]) && pos < item.length()){
            holdstring = holdstring + item[pos];
            pos++;
        }
        list.push_back(Token(holdstring));
        while(!isdigit(item[pos]) && pos < item.length())
        {
            holdstring = item[pos];
            list.push_back(Token(holdstring));
            pos++;
        }
    }
//    printVector();
}
void Tokenizer::printVector()
{
    int i = 0;
    cout << "size: " << list.size() << endl;
    while(i < list.size()){
        cout << list[i].getToken();
        i++;
    }
}

vector<Token> Tokenizer::getlist()
{
    return list;
}

int Tokenizer::getsize()
{
    return list.size();
}

#endif // TOKENIZER
