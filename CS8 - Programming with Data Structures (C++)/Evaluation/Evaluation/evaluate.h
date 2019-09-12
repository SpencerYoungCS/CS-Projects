#ifndef EVALUATE
#define EVALUATE
#include "tokenizer.h"
//-----------------------THIS WILL EXECUTE MY TOKENIZER AND CONVERT TO INFIX THEN CALCULATE IT------------
class Evaluate{
public:
    Evaluate();
    Evaluate(string exp);
    string getResult();
    int Precedence(Token token);
    queue<Token> InfixToPostfix();  //this will convert the string into post fix
    void QueuePrint(queue<Token> toPrint);
    string Math();
    Token calculate(int lhs, int rhs, string op);


private:
    stack<Token> stk;
    vector<Token> List;
    queue<Token> output;
    string result;

};

Evaluate::Evaluate()
{
}

Evaluate::Evaluate(string exp)
{
    Tokenizer Temp(exp);
    List = Temp.getlist(); // this is the list
    output = InfixToPostfix(); //this is the queue (i made this so that the function isnt called over and over
    result = Math(); //result is the evaluated expression.

}

string Evaluate::getResult()
{
return result;
}


int Evaluate::Precedence(Token token){
    if(!token.NumberChecker()){
        switch(token.getToken()[0]){
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        case '^':
            return 4;
        default:
            cout << "Unknown Operator" << endl;
            break;
        }
    }
    else
        return 0;
}

queue<Token> Evaluate::InfixToPostfix()
{
    queue<Token> result;
    for(int i = 0; i < List.size(); i++){
        if(List[i].isDigit()){  //checks if the token is a number
            result.push(List[i]);
        }
//        else if(!List[i].isDigit()){
//            if(List[i].getToken()[0] == '('){
//                cout << "open bracket" << endl;

////            stk.pop();
//            }
//            else if(List[i].getToken()[0] == ')'){
//                cout << "close breacket" << endl;
////                stk.pop();
//            }
//        }
        else if(!List[i].isDigit()){
            while(!stk.empty() && (Precedence(List[i]) <= Precedence(stk.top()))){ // precedence check!
                result.push(stk.top());
                stk.pop();
            }
            stk.push(List[i]);
        }
    }

    while(!stk.empty()){
        result.push(stk.top());
        stk.pop();
    }
    return result;

}

void Evaluate::QueuePrint(queue<Token> toPrint)
{
    queue<Token> temp; //i have a temporary queue instead of directly
    //printing it because, althouhg infixtopostfix returns a queue, it would continueously run the code.
    temp = toPrint;

    int i = 0;
    int j = temp.size();
    while(i < j){
        cout << temp.front().getToken();
        temp.pop();
        i++;
    }
    cout << endl;
}

string Evaluate::Math()
{
    //this is where it will calculate the problem

    stack<Token> stk;
    queue<Token> TempOutput;
    TempOutput = output;
    while(!TempOutput.empty()){
        int lhsOperand; //these initializations will be renewed everytime
        int rhsOperand;
        if(TempOutput.front().isDigit()){
            stk.push(TempOutput.front());
//            cout << stk.top().getToken(); //this is purely for testing, seeing where im getting error
            TempOutput.pop();
        }
        else if(!TempOutput.front().isDigit()){
            istringstream rhsbuffer(stk.top().getToken()); //this will convert strings to ints for calculation
            rhsbuffer >> rhsOperand; // this puts the converted int into our lhsOperand
//            cout << "rhsOperand: " << rhsOperand << endl;
            stk.pop();
            istringstream lhsbuffer(stk.top().getToken());
            lhsbuffer >> lhsOperand;
//            cout << "lhsOperand: " << lhsOperand << endl;
            stk.pop();
            stk.push(calculate(lhsOperand,rhsOperand, TempOutput.front().getToken()));
            TempOutput.pop();
        }
    }
    return stk.top().getToken();
}

Token Evaluate::calculate(int lhs, int rhs, string op)
{
    string output;
    ostringstream convert;
    //find result then convert back to string
    Token temp;
    int result = 0;
    switch(op[0]){
    case '+':
        result = lhs + rhs;
        convert << result;
        output = convert.str(); //this will contain the int as a string
        temp.SetToken(output);
        return temp;
    case '-':
        result = lhs - rhs;
        convert << result;
        output = convert.str();
        temp.SetToken(output);
        return temp;
    case '*':
        result = lhs * rhs;
        convert << result;
        output = convert.str();
        temp.SetToken(output);
        return temp;
    case '/':
        result = lhs / rhs;
        convert << result;
        output = convert.str();
        temp.SetToken(output);
        return temp;
    case '^':
        if(rhs > 0)
            result = lhs;
        for(int i = 1; i < rhs; i++)
            result = result *lhs;
        convert << result;
        output = convert.str();
        temp.SetToken(output);
        return temp;
    }

}
#endif // EVALUATE
