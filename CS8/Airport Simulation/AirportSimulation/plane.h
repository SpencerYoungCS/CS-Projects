#ifndef PLANE
#define PLANE
#include <iostream>
#include <queue>


using namespace std;
enum status{takeoff, landing};
class Plane {// this will act like a token
public:
    Plane();
    Plane(status stat);
    status getStatus();//accessor
private:
    status Status;
    //    int clockStart;
};



Plane::Plane(status stat)
{
    switch(stat){
    case takeoff:
//        cout <<"taking off" << endl;
        Status = takeoff;
        break;
    case landing:
//        cout << "landing" << endl;
        Status = landing;
        break;
    default:
        cout << "error: no status" << endl;

    }
}

status Plane::getStatus()
{
   return Status;
}

#endif // PLANE
