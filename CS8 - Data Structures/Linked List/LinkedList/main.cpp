#include "list.h"
#include "frequency.h"
#include "map.h"

int main()
{
    srand (time(NULL));
//    //LIST TESTS-----------------------------------------------
    List<string> A;
    A.insertHead("test");
    A.insertHead("test");
    A.insertHead("test");
    A.insertHead("this");
    A.insertBefore(A.search("this"), "before");

    A.PrintList();
//    A.insertAfter(A.search("test"),"water");

//    A.insertAfter(A.at(1),"what");
//    A.PrintList();
//    cout << "Deleting at 3: "; A.DeleteThis(A.at(3));
//    A.PrintList();
//    cout << "Count: " << A.count() << endl;
//    A.deleteRepeats();
//    List<string> D;
//    D.insertHead("otherlist");
//    D.insertHead("otherlist");
//    A.insertHead(D.remove(D.at(1))->item);
//    cout << "List D Should have 1 Link: "; D.PrintList();
//    D.PrintList();
//    A.PrintList();
//    A.insertBefore(A.search("what"), "this before");
//    A.PrintList();
//    A.reverse();
//cout << "b4 shuffle" << endl;
//    A.PrintList();
//    A.insertHead("what");
//    A.deleteRepeats();
//    A.PrintList();
//    A.merge(D.gethead());
//    A.PrintList();
//    A.Shuffle();
//    cout << "after shuffle" << endl;
//    A.print();
//A.Merge(D.gethead());
//cout << "A.count(): " << A.count() <<endl;

//    A.print();
//    List<int> B;
//    B.insertHead(4);
//    B.insertAfter(B.search(4),5);
//    B.insertSorted(10);
//    B.insertHead(8);
//    B.insertSorted(7);
////    B.sort();
//    B.PrintList();
//    cout << "B.count(): " << B.count() << endl;
//    B.Shuffle();
//    B.print();
//    List<char> C;
//    C.insertHead('Q');
//    C.insertAfter(C.Search('Q'),'T');
//    C.insertHead('C');
//    C.insertHead('R');
//    C.insertHead('U');
//    cout << "main C count: " << C.count() << endl;
//    C.print();
//    C.Shuffle();
//    C.print();


    //FREQUENCY TEST----------------------------------

Frequency<int> F;
F.Insert(3);
F.Insert(3);
F.Insert(4);
F.Insert(9);
F.Insert(9);
F.Insert(4);
F.Insert(9);
//F.DeleteThis(A.search(3));
//F.insert(5);
//F.insert(3);
//F.insert(3);
F.PrintList();
//F.sort();
//F.print();
//F.Reverse();
//F.print();
//cout << "F.Search(4)->UniqueValue: " << F.search(4)->item.UniqueValue << endl;
//cout << "F[4]: " <<  F[4] << endl;


//Frequency<char> B;
//B.insert('a');
//B.insert('s');
//B.insert('g');
//B.insert('d');
//B.insert('a');
//B.insert('g');
//B.insert('a');
//B.Reverse();
//cout << "B['a']: " <<  B['a'] << endl;
//B.print();

//Frequency<char> C;
//C.insert('f');
//C.insert('g');
//C.insert('s');
//C.insert('t');

//B.Merge(C.gethead());
//B.Delete(B.Search('a'));
//B.print();

//    //MAP TEST-----------------------------------------
Map<int,int> D;
D.Insert(1);
D.Insert(1);
D.Insert(1);
D.Insert(4);
D.Insert(7);
D.Insert(7);
cout << "D[3]: " << D[3] << endl;
D.DeleteThis(D.SearchList(1));
D.PrintList();
Map<int,int> Q;
Q.Insert(3);
Q.Insert(1);
Q.Insert(7);
Q.Insert(6);
Q.Insert(3);
Q.PrintList();
D.MergeThis(Q.gethead());
D.PrintList();
//D[1] = 25;
//cout << "D[1]: " << D[1] << endl;
//D.print();
//Map<char,int> E;
//E['R'] = 20;
//E['Q'] = 10;
//E['T'] = 6;
//E.print();

//cout << E['R'] << endl;
    return 0;
}
