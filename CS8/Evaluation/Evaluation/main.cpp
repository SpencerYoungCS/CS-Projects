#include <evaluate.h>

int main(){

//How this works, Evaluate will call call tokenizer, where it will
//    take a string from the user. it will seperate the operators with the operands
//            and return it as a string.
//    then evaluate will call InfixToPostfix function where it will convert the list into a queue
//    and be in post fix notation.
//    then, the function math() will simply do the calculation.


//---------------------------THESE ARE THE TESTS--------------------------------------------
Evaluate A("4+5-2*9"); // and -9
Evaluate B("1+5*2*9"); // ans 91
//Evaluate C("4+(5-2)*9"); // ans is 31
Evaluate D("4/5-2*9");

cout << "Evaluated: " << A.getResult() << endl; // this shows the expression fully evaluated

cout << "Evaluated: " << B.getResult() << endl; // this shows the expression fully evaluated

cout << "Evaluated: " << D.getResult() << endl; // this shows the expression fully evaluated

    return 0;
}

