#ifndef COUNTERTYPE_H
#define COUNTERTYPE_H

class CounterType
{
public:
    CounterType();
    CounterType(int newx);
    //Accessors
    int getx();
    //Mutators
    void setx(int newx);

private:
    int x;

};

#endif // COUNTERTYPE_H
