#include <iostream>
#include "point.h"
#include "line.h"
#include "triangle.h"

#include <cmath>

using namespace std;

int main()
{
//    cout << "TESTING Line(Point(1,1), Point(2,2)) DISTANCE FORMULA" << endl;


    Point A;

    A.setboth(1,1);
    Point B;

    B.setboth(2,0);

    Point C;

    C.setboth(4,2);
    Line L1;
    Line(A, B);
    
    



    cout << "Distance: "; cout << L1.distance(A, B) << endl;
//    cout << endl;

    //-----------------------------------------------------------------



    L1.findslope(A,B);


    cout << "TESTING GETSLOPE AND FINDSLOPE: " << L1.getslope(); cout << endl;
    cout << "Testing Y-Intercept: " << L1.yintercept(A); cout << endl << endl;





    Triangle(A,B,C);
    Triangle Q;


    cout << "TESTING PERIMETER: " << Q.perimeter(A,B,C) << endl;
    cout << "TESTING SURFACE AREA: " << Q.surfacearea(A,B,C) << endl;






    return 0;
}

//---------------------------------------------------------------


