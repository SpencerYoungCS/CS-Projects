#include <iostream>
int* Allocate(int size);
int** Allocate2D(int* sizes, int rows);
int ptrlen(int *ptr);
void intread(int** toread, int row, int column);
void intwrite(int** writeto, int replace,int row, int column);
int intverify(int row, int column);
void print(int** printthis);
void intdelete(int **intptr, int rows);
int intsearch1d(int* tosearch, int key, int &colstart);
void intsearch2d(int** tosearch, int key, int maxrows,int &colstart, int &rowstart );

using namespace std;

int main()
{
    //---------------------------------------------THIS IS MY 2D ALLOCATE TEST------------------------------------
    int size[50];
    int* ptrsize = size;
    int rows;

    int rowstart = 0;
    int colstart = 0;

    cout << "Please enter # of Rows: ";
    cin >> rows;

    for (int i = 0; i != rows; i++)
    {
        cout << "Please enter the size of Row [" << i << "]: ";
        cin >> size[i];
        size[i+1] = -1;
    }

    int** hold2D = Allocate2D(ptrsize, rows); //creating Pointer Array

    for (int i = 0; i < rows; i++)
    {
        cout << "Row [" << i << "] : ";
        for(int j = 0; j < size[i]; j++)
        {
            intwrite(hold2D, 0, i, j);
            cout << hold2D[i][j];
        }
        cout << endl;
    }



    cout << "intsearch2d: 0 location is :";
    intsearch2d(hold2D, 0, rows, colstart, rowstart);
    cout << "[" << rowstart << "][" << colstart << "]" << endl;


    intdelete(hold2D, rows);

    //-----------------------------------------------------------------------------------------------------------



    return 0;
}

int* Allocate(int size)
{
    int *temp = new int[size+1];
    temp[size] = -1;

    return temp;
}

int** Allocate2D(int* sizes, int rows)
{
    int ** hold2D = new int*[rows];
    for(int i = 0; i < rows; i++)
    {
        hold2D[i] = Allocate(sizes[i]);
    }
    return hold2D;
}

int ptrlen(int* ptr)
{
    int i = 0;
    while(*ptr != -1)
    {
        ptr++;
        i++;
    }
    return i;
}

void intread(int** toread, int row, int column)
{
    cout << toread[row][column];
}

void intwrite(int** writeto, int replace,int row, int column)
{
    writeto[row][column] = replace;
}

int intverify(int row, int column, int maxrow, int maxcolumn)
{
    if((row > maxrow) || (column > maxcolumn))
        return -1;
    else
        return 1;
}

int intsearch1d(int* tosearch, int key, int &colstart)
{
    tosearch = tosearch + colstart;
    while(*tosearch != -1)
    {
        if (*tosearch == key)
        {
            return colstart;
        }
        *tosearch++;
        colstart++;
    }
    return -1;

}


void intsearch2d(int** tosearch, int key, int maxrows,int &colstart, int &rowstart )
{
    while(rowstart != maxrows)
    {
        if(intsearch1d(*tosearch, key, colstart) != -1)
        {
            return;
        }
        *tosearch++;
        colstart = 0;
        rowstart++;
    }
    rowstart = -1;
    colstart = -1;
    return;
}

void print(int** printthis)
{
    while(*printthis)
    {
        cout << **printthis;
        printthis++;
        cout << endl;
    }
    printthis++;
    cout << endl;

}

void intdelete(int** intptr, int rows)
{

    for(int i =0; i != rows; i++)
    {
        delete[]*intptr;
        intptr++;
    }
}
