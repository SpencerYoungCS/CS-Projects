#include <iostream>
#include "graph.h"

using namespace std;
using namespace main_savitch_15;

int main()
{
//    cout << "test" << endl;
//----------------------------------BARKESHILI LOOK HERE! TESTING THAT THE IMPLEMENTED GRAPH WORKS CORRECTLY!----------------------
    graph<int> a;
//    a.add_vertex(1);
    a.add_vertex(1);
    a.add_vertex(14);

    a.add_edge(1,0,100);

    if(a.is_edge(1,0)){
        cout << "This edge exists" << endl;
    }
    cout << "a[1]: " << a[1] << endl;



    a[1] = 10;

    cout << "Redefinition a[1]: "<< a[1] << endl;


    //---------------------------------------NOW TESTING TO SEE IF THEY HAVE WEIGHT!!!----------------------------------------

    cout << "the weight of the edge [1][0] is: " << a.is_weight(1,0) << endl;


    //it works!-----------------------------






    return 0;
}

