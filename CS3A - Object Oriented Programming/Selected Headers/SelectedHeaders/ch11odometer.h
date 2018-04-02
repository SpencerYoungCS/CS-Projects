#ifndef CH11ODOMETER_H
#define CH11ODOMETER_H

class Odometer
{
public:
    Odometer();
    Odometer(int Miles = 0, int MPG = 0);
    //Mutators
    void resetOdometer(int Miles = 0, int MPG = 0);
    void setMPG(int newMPG);
    void setMiles(int newMiles);
    void gasconsumed();

private:
    int Miles;
    int MPG;
};

#endif // CH11ODOMETER_H
