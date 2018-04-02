#include <iostream>

using namespace std;

int main()
{
    char word[] = "Testing!!"; // this will be the character array my character pointer will point to

    char *cpt = word; //Using the * will create a pointer that points to the first index of the array "word"
    //, which is "[T]esting!!"
    cout << *cpt << endl; // this displays the pointer's location "T"
    cout << cpt << endl; // this displays the entire array....

    cpt++; // this advances the pointer by the index of one
    cpt--; // this decreases the pointer's index by one

    char bacon[50];

    bacon[0] = *cpt;
    bacon [1] = '\0';

    cout << bacon << endl; // because *returns what is inside the first index, i can use that and put it in another location,
    // like this test character array called bacon;

    int num[10] = {1,2,3,4,5};

    int *ipt = num; // this integer pointer points at num.

    cout << *ipt << endl; // as usual this has the beginning of the int array.

    ipt++;  // functions similarly to character pointers, except for integer arrays.

    cout << *ipt << endl;


    return 0;
}

