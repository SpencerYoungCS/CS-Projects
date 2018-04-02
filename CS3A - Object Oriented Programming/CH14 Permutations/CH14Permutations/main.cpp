#include <iostream>

using namespace std;

void permutation(char a[], int start, int length);
int charlength(char a[]);

int main()
{
    int start = 0;

//    char a[10] = "abc";

    char word[50];
    cout << "what word would you like to permutate? " << endl;
    cin >> word;
    int length = charlength(word)-1; //-1 because it should stop at end location, not length

//    permutation(a,start, length); //test permutation

    permutation(word,start,length);

    return 0;
}


void permutation(char a[], int start, int length)
{
    int j = 0;
    if (start == length)                  // if start reaches the end, return it.
        cout << "char a: " <<  a << endl;
    else{
        for (j = start; j <= length; j++){ // starting from a[0] to a[3], otherwise length
            swap(a[start], a[j]);
            permutation(a, start+1, length);  //begin recursion starting from next spot
            swap(a[start], a[j]);    // Set it back after leaving the recursion
        }
    }
}


int charlength(char a[]){
    int i = 0;
    while (a[i] != NULL)
        i++;
    return i;
}
