#include <iostream>

using namespace std;
#include "simplecompare.h"
#include "templatedcompare.h"
#include "random.h"

const int MAX = 10;

void TestRandom();
void TestSort();
void TestSortFunctor();
void TestCharSort();

void FillArray(int a[], int size);
void FillArray(char s[], int size);
void PrintArray(int a[], int size);
void SortArray(int a[], int size);
template <typename T>
void Swap(T& a, T& b);

template <typename compare>
void SortArray(int a[], int size, compare cmp);

template <typename T, typename compare>
void SortArray(T a[], int size, compare cmp);



int main()
{
    cout <<endl<<endl<<endl << "=====================" << endl<<endl<<endl<<endl;
    TestCharSort();
    cout<<endl<<endl<<"---------------"<<endl;
    //TestSortFunctor();

    cout <<endl<<endl<<endl << "=====================" << endl;
    return 0;
}
void TestCharSort(){
    char s[MAX*2];
    FillArray(s, MAX*2);
    cout<<s<<endl;
    SortArray(s,MAX*2-1,Bigger<char>());
    cout<<s<<endl;
    SortArray(s,MAX*2-1,Smaller<char>());
    cout<<s<<endl;
}

void TestSort(){
    int a[MAX];
    FillArray(a, MAX);
    PrintArray(a, MAX);
    SortArray(a, MAX);
    PrintArray(a, MAX);

}
void TestSortFunctor(){
    int a[MAX];
    FillArray(a, MAX);
    PrintArray(a, MAX);
    cout<<endl<<"Ascending..."<<endl;
    SortArray(a, MAX,Greater());
    PrintArray(a, MAX);
    cout<<endl<<"Descending..."<<endl;
    SortArray(a, MAX,Less());
    PrintArray(a, MAX);

}

void TestRandom(){
    Random r;
    while (true){
        cout<<r.GetNext(0,6);
        cin.get();
    }

}
void FillArray(char s[], int size){
    Random r;
    for (int i=0; i<size-1; i++){
        s[i] = 'a'+r.GetNext(0,25);
    }
    s[size-1]=NULL;
}

void FillArray(int a[], int size){
    Random r;
    for (int i=0; i<size; i++){
        a[i] = r.GetNext(0, 100);
    }
}

void PrintArray(int a[], int size){
    for (int i=0; i<size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void SortArray(int a[], int size){
    bool flag = true;
    for (int i=1; i<size && flag; i++){
        flag = false;
        for (int j=0; j<size-1; j++){
            if (a[j]<a[j+1]){
                flag = true;
                Swap(a[j],a[j+1]);
            }
        }
    }
}

template <typename T>
void Swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}


//------------------------
template <typename compare>
void SortArray(int a[], int size, compare cmp){
    bool flag = true;
    for (int i=1; i<size && flag; i++){
        flag = false;
        for (int j=0; j<size-1; j++){
            if (cmp(a[j],a[j+1])){
                flag = true;
                Swap(a[j],a[j+1]);
            }
        }
    }
}


template <typename T, typename compare>
void SortArray(T a[], int size, compare cmp){
    bool flag = true;
    for (int i=1; i<size && flag; i++){
        flag = false;
        for (int j=0; j<size-1; j++){
            if (cmp(a[j],a[j+1])){
                flag = true;
                Swap(a[j],a[j+1]);
            }
        }
    }
}
