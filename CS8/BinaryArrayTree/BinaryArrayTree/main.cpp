#include "avltree.h"
int main()
{

    AVLtree<int> a; //TESTING ------ FIRST MAKE SURE THE TREE WORKS....
    a.insert(3);
    a.insert(2);
    a.insert(6);
    a.insert(8);
    a.preOrder();
    //------------------ARRAY TEST!! LOOK HERE!!!--------------------------
    cout << "a[0]: " << a[0] << endl;
    cout << "a[1]: " << a[1] << endl;
    cout << "a[2]: " << a[2] << endl;
    cout << "a[3]: " << a[3] << endl;
    cout << "size: " << a.size() << endl;




    return 0;
}

