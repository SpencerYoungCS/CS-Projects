#include "cursorlist.h"

CursorList::CursorList():List(){
    cursor = 0;
    length = 0;
}

CursorList::CursorList(List A): List(A){
    cout << "Commands: A for Left, S for Right, D for Delete" << endl;
    cout << "	  W for Insert After, and E for Insert Before!" << endl;
    cout << "Your List: "; printcursor(); cout << endl;
}

void CursorList::GoNext(){
    if(cursor > length){
    }
    else
        cursor++;

    printcursor();
    cin >> action;
    exec(action);
}

void CursorList::GoPrev(){
    if(cursor == 0){
    }
    else
        cursor--;

    printcursor();
    cin >> action;
    exec(action);
}

void CursorList::printcursor(){
    node* walker = gethead();
    int i = 0;
    int flag = 0; //indicates if cursor was already printed

    while(walker != NULL){
        if (i == cursor){
            cout << "[" << walker->item<<"]" << " ";
            i++;
            flag = 1;
            temp = walker;
        }
        else if(flag == 0 && walker->next == NULL){

            cout << "[" << walker->item<<"]" << " ";
            flag = 1;
            temp = walker;
        }
        else if(walker != NULL){
            cout << walker->item << " ";
            i++;
        }
        walker = walker->next;
    }
    cout << "NULL" << endl;
    length = i-2;
    cin >> action;
    exec(action);
}

void CursorList::exec(char action){
int num = 0;
    switch(action){
    case 'a':
    case 'A':
        GoPrev();
    case 's':
    case 'S':
        GoNext();
    case 'd':
    case 'D':
        Remove(temp);
        printcursor();
    case 'w':
    case 'W':
        cout << "Insert After: "; cin >> num;
        insertAfter(temp,num);
        printcursor();
    case 'e':
    case 'E':
        cout << "Insert Before: "; cin >> num;
        insertBefore(temp,num);
        printcursor();

    default:
        cout << "Enter a valid command" << endl;
        cin >> action;
    }



}
