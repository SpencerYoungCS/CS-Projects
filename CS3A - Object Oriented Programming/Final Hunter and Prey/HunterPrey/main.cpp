//#include <iostream>
#include "world.h"
#include "mygui.h"
#include "glwidget.h"

//void print(world printthis);
void locationchecker(world check, int j, int i);
//using namespace std;

int main(int argc, char **argv)
{
    srand(time(NULL));
    world A;
    cout << "-----------------Clear Field----------------" << endl;
    A.print();

    cout << "---------------Randomized Field--------" <<endl;
//    A.randomize();
//    A.print();
//    cout << endl;



//    for(int i = 0; i < 5; i++)
//    {
//        cout << "----------step " << i << " -------------" << endl;
//        cout << endl;
//        A.step();
//        A.print();
////        print(A);
//    }

//    cout << "step done" << endl;
//    A.print();

    QApplication app(argc, argv);

    MyGui window;
    window.show();
    return app.exec();


    //----------------------------------------------------------

    return 0;
}

//void print(world printthis)
//{
//    for (int j = 0; j < MAX_j; j++){
//        for(int i = 0; i < MAX_i; i++){
//            if(printthis.NewWorld[j][i] == NULL)
//                cout << "N";
//            else
//                cout << printthis.NewWorld[j][i]->genetype;
//        }
//        cout << endl;
//    }
//}


void locationchecker(world check, int j, int i){
    cout << "Location Checker: ";
    cout << endl;
    cout << "j: "; cin >> j;
    cout << "i: "; cin >> i;
    cout << endl;
    check.NewWorld[j][i]->get_point();
    cout << "genetype: " << check.NewWorld[j][i]->genetype << endl;
    cout << "hasMoved: " << check.NewWorld[j][i]->hasMoved << endl;
}


