#ifndef CURSORLIST_H
#define CURSORLIST_H
#include "list.h"

class CursorList : public List{
public:
    CursorList();
    CursorList(List A);
    void GoNext();
    void GoPrev();
    void printcursor();
    void exec(char action);
private:
    int cursor;
    char action;
    int length;
    node* temp = new node; //this will point at the cursor'd pointer
};
//A List with a current (cursor) pointer. Will have GoNext, GoPrev functions.
//The current pointer will adjust when we insert items into the list
#endif // CURSORLIST_H
