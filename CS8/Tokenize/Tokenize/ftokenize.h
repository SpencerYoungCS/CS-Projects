#ifndef FTOKENIZE
#define FTOKENIZE
#include "token.h"
#include "stokenize.h"
#include "frequency.h"

class FTokenize{
public:
    const int MAX_BLOCK = 50;
    FTokenize();
    FTokenize(char* fname);
    Token NextToken();
    bool GetNewBlock();
    bool More();
    int Pos();
    int BlockPos();
private:
    ifstream infile;
    STokenize stk;
    int pos;
    bool more;
};


FTokenize::FTokenize()
{

}

FTokenize::FTokenize(char *fname){
    string line;

        Token holdToken;

    Frequency<string> TokenList;


    ifstream myfile (fname);

    if (myfile.is_open()){
        stringstream textStream;
        textStream << myfile.rdbuf();
        line = textStream.str();
        STokenize stk(line);

        while(stk.More(line)){
            holdToken = stk.GetToken(line);
            TokenList.Insert(holdToken.TokenString());
//            cout << stk.GetToken(line).TokenString();
            TokenList.PrintList();
        }
        myfile.close();
    }
    else
        cout << "Unable to open file" << endl;
}

#endif // FTOKENIZE
