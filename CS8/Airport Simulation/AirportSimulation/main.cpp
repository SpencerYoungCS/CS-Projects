#include "pqueue.h"
void initialize(int &end_time, int &queue_limit, double &arrival_rate, double &departure_rate) ;
int main()
{

    Plane A(takeoff);
    Plane B(landing);
//    Plane C(takeoff);
//    Plane D(landing);
//    Plane E(takeoff);

    queue<Plane> test;

    test.push(A);
    cout << A.getStatus() << endl; //takeoff = 0
    cout << B.getStatus() << endl; //takeoff = 1
//    test.push(B);
//    test.push(C);
//    test.push(D);
//    test.push(E);

//    PQueue<Plane> test2(test);
//    test2.PrintList();
//    if(test2.front().getStatus() == landing)
//        cout << "success" << endl;


//    Input will be:
//    The amount of time needed for one plane to land
//    The amount of time needed for one plane to takeoff
//    The probability of a plane entering the landing queue in any given minute
//    The probability of a plane entering the takeoff queue in any given minute
//    The start time in minutes before midnight
//    The stop time in minutes before midnight
//    The maximum minutes until a plane waiting to land will crash
//    The output of the program will be:

//    Total simulation time
//    The number of planes that took off in the simulated time
//    The number of planes that landed in the simulated time
//    The number of planes that crashed because they ran out of fuel before they could land
//    The average time a plane spent in the takeoff queue
//    The average time a plane spent in the landing queue

//    return 0;



    int end_time; //time to run simulation
    int queue_limit; //size of Runway queues
    int flight_number = 0;
    double arrival_rate, departure_rate;
    initialize(end_time, queue_limit, arrival_rate, departure_rate);

    //my psuedo code-----------------------------------------------------------
    //use random, using rand 1+per-time-unit and if its between 1 and rate, then have plane arrive
    //need to input time to land, and time to takeoff

return 0;

}


void initialize(int &end_time, int &queue_limit,
                double &arrival_rate, double &departure_rate){

    cout << "This program simulates an airport with only one runway." << endl << "One plane can_land or depart in each unit of time." << endl;
    cout << "Up to what number of planes can be waiting to land "
         << "or take off at any time? " << flush;
    cin >> queue_limit;
    cout << "How many units of time will the simulation run?" << flush;
    cin >> end_time;
    bool acceptable;
    do {
        cout << "Expected number of arrivals per unit time?" << flush;
        cin >> arrival_rate;
        cout << "Expected number of departures per unit time?" << flush;
        cin >> departure_rate;
        if (arrival_rate < 0.0 || departure_rate < 0.0)
            cout << "These rates must be non-negative." << endl;
        else acceptable = true;
        if (acceptable && arrival_rate / departure_rate > 1.0)
            cout << "Safety Warning: This airport will become saturated."<< endl;
    } while (!acceptable);
}
