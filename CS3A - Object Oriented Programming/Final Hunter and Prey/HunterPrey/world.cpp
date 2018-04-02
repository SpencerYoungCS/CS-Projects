#include "world.h"

world::world()
{
    //THE FIELD
    for (int j = 0; j < MAX_j; j++)
        for(int i = 0; i < MAX_i; i++)
            NewWorld[j][i] = NULL;
//    WALLS
    //TOP WALL
    for(int i = 0; i < MAX_i; i++){
        NewWorld[0][i] = new wall;
        NewWorld[0][i]->set_point(0,i);
    }
    //LEFT WALL
    for(int j = 0; j < MAX_j; j++){
        NewWorld[j][0] = new wall;
        NewWorld[j][0]->set_point(j,0);
    }
    //RIGHT WALL
    for(int j = 0; j < MAX_j; j++){
        NewWorld[j][MAX_i-1] = new wall;
        NewWorld[j][MAX_i-1]->set_point(j,MAX_i-1);
    }
    //BOTTOM WALL
    for(int i = 0; i < MAX_i; i++){
        NewWorld[MAX_j-1][i] = new wall;
        NewWorld[MAX_j-1][i]->set_point(MAX_j-1,i);
    }
}

void world::randomize(){

    //generates either a 1 or 2 in each value of grid
    int random_j = 0;
    int random_i = 0;

    for(int i = 1; i < (MAX_i * 100); i++)
    {
        random_j = rand()%(MAX_j-2)+1;
        random_i = rand()%(MAX_i-2)+1;
        NewWorld[random_j][random_i] = NULL;
        NewWorld[random_j][random_i] = new ants;
        NewWorld[random_j][random_i]->set_point(random_j,random_i);
    }
    for(int i = 1; i < (MAX_i * 5); i++)
    {
        random_j = rand()%(MAX_j-2)+1;
        random_i = rand()%(MAX_i-2)+1;
        NewWorld[random_j][random_i] = NULL;
        NewWorld[random_j][random_i] = new doodlebugs;
        NewWorld[random_j][random_i]->set_point(random_j,random_i);
    }
}

void world::step()
{
    //DOODLEBUG STEP-------------------------
    for(int j = 1; j < MAX_j; j++)
    {
        for(int i = 1; i < MAX_i; i++)
        {
            if(NewWorld[j][i] == NULL || NewWorld[j][i]->hasMoved == true)
            {
            }
            else if (NewWorld[j][i]->genetype == 2)// if doodlebug......
            {
                NewWorld[j][i]->move(); //this will generate its next direction it will move

                if(checkprey(NewWorld[j][i]->coordinate.j,NewWorld[j][i]->coordinate.i) == true){ // this checks if an ant exists next to it, if true...
                     while(NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i] == NULL || NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->genetype == 9
                           || NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->genetype == 2){
                         NewWorld[j][i]->move();//repeat move until it hits genetype 1, ant
                     }
                }

                if(NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i] == NULL)//if next direction is on NULL
                {
                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i] = new doodlebugs;
                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]
                                    ->set_point(NewWorld[j][i]->next.j,NewWorld[j][i]->next.i); //coordinates
                    //for newly moved doodlebug;

                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->hasMoved = true; //has moved;
                    NewWorld[j][i]->hasMoved = true; //has moved;

                    //this will increase the not eaten count by 1
                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->notEaten =
                                    NewWorld[j][i]->notEaten + 1;
                    //this will increase breedcount by 1
                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breedCount =
                                    NewWorld[j][i]->breedCount + 1;

                }

                else if(NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->genetype == 1){//if moves on ant
                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i] = NULL;// reset to null
                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i] = new doodlebugs;
                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]
                                    ->set_point(NewWorld[j][i]->next.j,NewWorld[j][i]->next.i); //coordinates
                    //for newly moved doodlebug;

                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->hasMoved = true; //has moved;
                    NewWorld[j][i]->hasMoved = true; //has moved;

                    //this will set eaten back to zero
                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->notEaten = 0;
                    NewWorld[j][i]->notEaten = 0;
                    //this will increase breedcount by 1
                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breedCount =
                                    NewWorld[j][i]->breedCount + 1;

                }
                else
                {
                    //do nothing
                }
                //if breedcount == 8, make new doodlebug
                if(NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breedCount == 8){
                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breed();
                    //this will keep randomly checking sides until it can or can not breed;
                    if (checkant(NewWorld[j][i]->next.j , NewWorld[j][i]->next.i) == true){
                        while(NewWorld[NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.j][NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.i] != NULL)
                        {
                            NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breed();
                        }
                        NewWorld[NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.j][NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.i] = new doodlebugs;
                        NewWorld[NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.j][NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.i]
                                ->set_point(NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.j, NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.i);
                        NewWorld[NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.j][NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.i]->hasMoved = true;
                        //set breed back to zero
                        NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breedCount = 0;

                    }
                    else
                    {
                    }
                }
                //this checks if it moved 3 times without eating an ant
                if(NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->notEaten == 3){
                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i] = NULL;
                }
            }
            //removes its original location
            if(NewWorld[j][i] != NULL){
                if(NewWorld[j][i]->hasMoved == true)//has moved;
                {
                    NewWorld[j][i] = NULL;
                }
                else
                {
                    //do nothing
                }
            }
        }
    }

    //    set to all false
    for(int j = 1; j < MAX_j; j++)
    {
        for(int i = 1; i < MAX_i; i++)
        {
            if(NewWorld[j][i] != NULL)
            {
                NewWorld[j][i]->hasMoved = false;
            }
        }
    }

    //ANT STEP------------------------------------------------------

    for(int j = 1; j < MAX_j-1; j++)
    {
        for(int i = 1; i < MAX_i-1; i++)
        {
            if(NewWorld[j][i] == NULL || NewWorld[j][i]->hasMoved == true)
            {
            }
            else if (NewWorld[j][i]->genetype == 1)// if ant....
            {
                NewWorld[j][i]->move();

                //this will keep randomly checking sides until it can or can not breed;
                if (checkant(NewWorld[j][i]->coordinate.j , NewWorld[j][i]->coordinate.i) == true){
                    if(NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i] == NULL)
                    {
                        //do nothing
                    }
                    else{
                        while(NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i] != NULL)
                        {
                            NewWorld[j][i]->move();
                        }
                    }
                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i] = new ants;
                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]
                                    ->set_point(NewWorld[j][i]->next.j,NewWorld[j][i]->next.i); //coordinates
                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->hasMoved = true; //has moved;
                    NewWorld[j][i]->hasMoved = true; //has moved;

                    //this will increase breedcount by 1
                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breedCount =
                                    NewWorld[j][i]->breedCount + 1;

                    //if breedcount == 3, make new ant
                    if(NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breedCount == 3){
                        NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breed();
                        //this will keep randomly checking sides until it can or can not breed;
                        if (checkant(NewWorld[j][i]->next.j , NewWorld[j][i]->next.i) == true){

                            if(NewWorld[NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.j][NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.i] == NULL)
                            {
                                //do nothing
                            }
                            else{
                                while(NewWorld[NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.j][NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.i] != NULL)
                                    NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breed();
                            }

                            NewWorld[NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.j][NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.i] = new ants;
                            NewWorld[NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.j][NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.i]->set_point(NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.j, NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.i);
                            NewWorld[NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.j][NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breednext.i]->hasMoved = true;
                            //set breed back to zero
                            NewWorld[NewWorld[j][i]->next.j][NewWorld[j][i]->next.i]->breedCount = 0;

                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        //do nothing if breed isnt 3
                    }
                }
                //removes its original location
                if(NewWorld[j][i] != NULL){
                    if(NewWorld[j][i]->hasMoved == true)//has moved;
                    {
                        NewWorld[j][i] = NULL;
                    }
                    else
                    {
                        //do nothing
                    }
                }
            }
            else
            {
                //do nothing
            }

        }
    }


    //set all to has moved false
    for(int j = 1; j < MAX_j-2; j++)
    {
        for(int i = 1; i < MAX_i-2; i++)
        {
            if(NewWorld[j][i] != NULL)
            {
                NewWorld[j][i]->hasMoved = false;
            }
        }
    }
}


bool world::checkant(int j, int i)
{
    if(NewWorld[j-1][i] == NULL) // above
        return true;
    else if(NewWorld[j+1][i] == NULL) // below
        return true;
    else if(NewWorld[j][i+1] == NULL) //right
        return true;
    else if(NewWorld[j][i-1] == NULL) // left
        return true;
    else
        return false;

}

bool world::checkprey(int j, int i)
{
    if(NewWorld[j-1][i] == NULL){ //above
    }
    else{
        if(NewWorld[j-1][i]->genetype == 1)
            return true;
    }

    if(NewWorld[j+1][i] == NULL){ // below
    }
    else{
        if(NewWorld[j+1][i]->genetype == 1)
            return true;
    }

    if(NewWorld[j][i+1] == NULL){ //right
    }
    else{
        if (NewWorld[j][i+1]->genetype == 1)
            return true;
    }

    if(NewWorld[j][i-1] == NULL){ //left
    }
    else{
        if (NewWorld[j][i-1]->genetype == 1)
            return true;
    }
    return false;

}

void world::print()
{
    for (int j = 0; j < MAX_j; j++){
        for(int i = 0; i < MAX_i; i++){
            if(NewWorld[j][i] == NULL)
                cout << "N";
            else
                cout << NewWorld[j][i]->genetype;
        }
        cout << endl;
    }
}

//void world::circle()
//{
//    //enables it to be circular

//    for(int i = 0; i < MAX_i; i++)
//    {

//        NewWorld[1][0] = NewWorld[i][MAX_i - 1];
//        NewWorld[i][MAX_i] = NewWorld[i][1];
//        NewWorld[0][i] = NewWorld[MAX_i -1][i];
//        NewWorld[MAX_i][i] = NewWorld[1][i];
//    }
//    //Corners
//    NewWorld[0][0] = NewWorld[MAX_i-1][MAX_i-1]; //top left
//    NewWorld[0][MAX_i] = NewWorld[MAX_i - 1][1]; //top right
//    NewWorld[MAX_i][MAX_i] = NewWorld[1][1]; //bottom right
//    NewWorld[MAX_i][0] = NewWorld[1][MAX_i-1]; // bottom left
//}

