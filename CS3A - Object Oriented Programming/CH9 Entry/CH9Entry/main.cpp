#include <iostream>
#include <string>

using namespace std;

string* addEntry(string *dynamicArray, int& maxsize, const string newEntry);
string* deleteEntry(string *dynamicArray, int& maxsize, const string entryToDelete);
bool strcpr(const string first, const string that);
void exec(string* newlist, string* dynamicarray,char action, int& size);
int abs(const int i);

int main(){
    int maxsize = 0;
    char action;
    string* newlist = new string;
    string * names = new string[3];
    *names = "test";
    *(names+1) = "test2";
    *(names+2) = "test3";


    cout << "Commands: A  = Add Entry, D for Delete entry" <<  endl;
    cout << "Command: "; cin >> action;
    exec(newlist, names,action, maxsize);
    cout << "String : ";
    for (int i = 0; i < maxsize; ++i){
         cout << *(names + i) << " ";
    }
    cout << endl;

    return 0;

}


string* addEntry(string *dynamicArray, int& maxsize, const string newEntry){
    string *newDynamicArray = new string[maxsize + 1];
    for (int i = 0; i < maxsize; ++i)
        *(newDynamicArray + i) = *(dynamicArray + i);
    if (maxsize != 0)
        delete [] dynamicArray;
    *(newDynamicArray + maxsize) = newEntry;
    maxsize++;
    return newDynamicArray;
}
string* deleteEntry(string *dynamicArray, int& maxsize, const string entryToDelete)
{

    string *newDynamicArray = new string[abs(maxsize - 1)];
    int posToDelete;
    bool found = false;
    for (int i = 0; (i < maxsize) && (!found); ++i) {
        if (strcpr(dynamicArray[i],entryToDelete) ) {//comparing 2 string
            found = true;
            posToDelete = i;
        }
    }
    if (found) {
        for (int i = posToDelete; i < maxsize - 1; ++i)
            *(dynamicArray + i) = *(dynamicArray + i + 1);
        for (int i = 0; i < maxsize - 1; ++i)
            *(newDynamicArray + i) = *(dynamicArray + i);
        maxsize--;
        delete [] dynamicArray;
        return newDynamicArray;
    }
    cout << "DEBUG: not found" << endl;
    delete [] newDynamicArray;
    return dynamicArray;
}

bool strcpr(const string first, const string that)
{
    for (int i = 0; i < that.length(); ++i)
        if (that[i] != first[i])
            return false;
    return true;
}

int abs(const int i)
{
    return (i >= 0 ? i : -i);
}

void exec(string *newlist, string* dynamicarray, char action, int &size){
    switch(action){
    case 'a':
    case 'A':
        newlist = addEntry(newlist, size, *dynamicarray);
        break;
    case 'd':
    case 'D':
        newlist = deleteEntry(newlist, size, *dynamicarray);
        break;
    default:
        cout << "Enter a valid command" << endl;
        cin >> action;
    }
}
