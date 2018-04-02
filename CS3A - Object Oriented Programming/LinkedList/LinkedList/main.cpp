#include "sorted.h"
#include "stack.h"
#include "cursorlist.h"
#include "queue.h"
int main()
{
    List A;
    A.inserthead(5);
    A.inserthead(3);
    A.inserthead(234);
    A.inserthead(45);
    A.inserthead(3);
    A.inserthead(7);
    A.insertEnd(33);
//    cout << "Final List: ";
//    A.printlist();
//    A.printlist();
//    cout << endl;
//    cout << "Sorted List: ";
//    A.sort();
//    A.printlist();
//    cout << "THIS IS PASSED TO SORTED: ";
//    A.printlist();
//    cout << endl;
//    //    return 0;
////--------------------------------SORTED LIST TEST--------------------------------
//    cout << "Sorted list Test----------------------------------" << endl;
//    Sorted B(A);
//    cout << "B.printlist(): "; B.printlist();
////    cout << "A.printlist(): "; A.printlist();

//    cout << "B.printlist(); "; B.printlist();
////    cout << "A.printlist(); "; A.printlist();
////       return 0;

////-------------------------STACKED LIST TEST-----------------------------
//    cout << "Stacked list test----------------------------------" << endl;
//        Stack Q(A);


//        cout << "Push 3: ";
//        Q.Push(3);
//        Q.printlist();
//        cout << "Pop: ";
//        Q.Pop();
//        Q.printlist();
//        cout << "Top: " << Q.Top() << endl;
//        cout << endl;
//        //increasing the length of A for testing
//        A.inserthead(7);
//        A.inserthead(1);

//-----------------------------CURSORLIST TEST----------------------------------
        cout << "Cursored List test------------------------" << endl;

        CursorList P(A);
//        P.GoPrev();
//        P.GoNext();
//        P.GoNext();
//        P.GoNext();

        return 0;
}
