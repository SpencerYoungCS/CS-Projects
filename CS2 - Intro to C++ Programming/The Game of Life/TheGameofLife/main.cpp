#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>


using namespace std;


int cellchecker(char grid[][1000], char tempgird[][1000], int positioni, int positionj, bool &alive);
void linechecker(char grid[][1000], char tempgrid[][1000], int &positioni, int &positionj, bool &alive);
void gridchecker(char grid[][1000], char tempgrid[][1000], int &positioni, int &positionj, int &imax, bool &alive);
void gridreplace(char grid[][1000], char tempgrid[][1000], int imax);
void repeatgeneration(char grid[][1000], char tempgrid[][1000], int &positioni, int &positionj,  int &imax, bool &alive, int generations);
void loadfile(char filename[], char grid[][1000], int &imax);
void gridviewer(char grid[][1000], int imax);
void savefile(char grid[][1000], char filename[], int imax);
void randomize(char grid[][1000], int imax);
void newarray(char grid[][1000], int &imax);
void gridcircle(char grid[][1000], int imax);


int main()
{
    srand(time(NULL));

    //----------------------------VARIABLES/INITIALIZERS----------------------------------------------
    char grid[500][1000];
    char tempgrid[500][1000];
    char filename[999] = "grid.txt";    //Settings Text file
    int positioni = 0;
    int positionj = 0;
    int imax = 0;
    int generations = 0;
    bool alive = false;


    //-----------------------------------FILE IMPLEMENTATION---------------------------------------------


    cout << "------------------------------Original Grid----------------------------------" << endl << endl;

    loadfile("grid.txt", grid, imax);
    gridcircle(grid, imax);
    gridviewer(grid, imax);

    cout << endl;

    //-----------------------------------------Temporary Grid------------------------------------

    cout << endl;
    loadfile("grid.txt", tempgrid, imax);
    cout << endl;

    cout << "-------------------------------------------------------------------------------" << endl;


    cout << "Please enter the number of generations to be passed" << endl;
    cout << "Generations: ";
    cin >> generations;
    cout << endl;

    repeatgeneration(grid, tempgrid, positioni, positionj, imax, alive, generations);

    cout << "Do you want to save? (y/n)" << endl;
    char save;
    cin >> save;
    switch(save)
    {
    case 'y':
    case 'Y':
        savefile(grid,filename, imax);
        break;
    default:
        break;
    }


    cout << endl;



    return 0;
}


//srand(time(NULL));
//y = rand()%MAX;
//MAX is my variable



//--------------------------------LOWER LEVEL FUNCTIONS BELOW------------------------------------------------

void gridcircle(char grid[][1000], int imax)
{

    for(int i = 1; i < imax; i++)
    {

        grid[i][0] = grid[i][imax - 1];
        grid[i][imax] = grid[i][1];
        grid[0][i] = grid[imax -1][i];
        grid[imax][i] = grid[1][i];
    }
    //Corners
    grid[0][0] = grid[imax-1][imax-1]; //top left
    grid[0][imax] = grid[imax - 1][1]; //top right
    grid[imax][imax] = grid[1][1]; //bottom right
    grid[imax][0] = grid[1][imax-1]; // bottom left

}



void newarray(char grid[][1000], int &imax)
{
    imax = 50;
    for(int i = 0; i <= imax; i++)
    {
        for(int j = 0; j <= imax; j++)
        {
            grid[i][j] = 48;
        }
    }
}

void randomize(char grid[][1000], int imax)
{
    for(int i =0; i < (imax * 2); i++)
    {
        grid[(rand()%(imax-1))+1][(rand()%(imax-1))+1] = 49;
    }
}


void savefile(char grid[][1000], char filename[], int imax)
{
    ofstream outfile;
    outfile.open(filename);
    if(outfile.fail())
    {
        cout << endl;
        cout << "Error: SOMETHING REALLY WENT WRONG..." << endl;
        cout << "Terminating program..." << endl << endl;
        exit(0);
    }
    int i;
    for(i = 0; i < imax; i++)
    {
        outfile << grid[i] << endl;
    }
    outfile << grid[i];


    outfile.close();


}


void gridviewer(char grid[][1000], int imax)
{
    for(int i = 0; i <= imax; i++)
    {
        cout << "[" << grid[i] << "]" << endl;
    }
}

void loadfile(char filename[], char grid[][1000], int &imax)
{
    ifstream infile;

    infile.open(filename);

    if (infile.fail())  // Error Check
    {
        cout << endl;
        cout << "Error: File not found..." << endl;
        cout << "Terminating program..." << endl << endl;
        exit(0);
    }

    for(int i = 0; infile.eof() == false ; i++)
    {
        infile.getline(grid[i],100);
        imax = i;
    }

    infile.close();
}


void repeatgeneration(char grid[][1000], char tempgrid[][1000], int &positioni, int &positionj, int &imax, bool &alive, int generations)
{
    for(int i = 0; i < generations; i++)
    {
        gridcircle(grid, imax);
        gridchecker(grid, tempgrid, positioni, positionj, imax, alive);
        gridreplace(grid, tempgrid, imax);
        cout << endl;
    }
}


void gridreplace(char grid[][1000], char tempgrid[][1000], int imax)
{
    //this function replaces the temporary grid and puts it into the main grid
    for(int i = 0; i != imax + 1; i++)
    {
        cout << "[" << tempgrid[i] << "]" << endl;
    }

    for(int i = 0; i != imax + 1; i++)
    {
        for (int j = 0; tempgrid[i][j] != '\0'; j++)
        {
            grid[i][j] = tempgrid[i][j];
        }
    }
}


void gridchecker(char grid[][1000],char tempgrid[][1000], int &positioni, int &positionj, int &imax, bool &alive)
{
    //The uses linechecker for each line except the first and last line
    for(int i = 1; i != imax; i++)
    {
        positioni = i;
        linechecker(grid,tempgrid, positioni, positionj, alive);
    }
}

void linechecker(char grid[][1000],char tempgrid[][1000], int &positioni, int &positionj,bool &alive)
{
    //This cellchecks the line and exludes the first and last zeros.

    for(int i = 1; grid[positioni][i+1] != '\0'; i++)
    {
        positionj = i;
        cellchecker(grid, tempgrid, positioni, positionj, alive);
    }

    positionj = 0;

}

int cellchecker(char grid[][1000], char tempgrid[][1000], int positioni, int positionj, bool &alive)
{
    //this function will return how many neighbors a cell has and copies into a temporary array
    int livecells = 0;

    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j  < 2; j++)
        {
            int number = grid[i + positioni][j + positionj]-48; //this converts the string number into an integer

            livecells = livecells + number;

            number = 0;
        }
    }

    if (grid[positioni][positionj] == 49)
    {
        alive = true;
        if (livecells == 3 || livecells == 4)
        {
            tempgrid[positioni][positionj] = 49;
        }
        else
        {
            tempgrid[positioni][positionj] = 48;
        }

    }
    else
    {
        alive = false;
        if (livecells == 3)
        {
            tempgrid[positioni][positionj] = 49;
        }
    }



    //        cout << "Total Live cells around position[" << positioni << "][" << positionj << "]: " << livecells << endl;
    //        cout << "Alive: " << alive << endl;

    return livecells;
}

