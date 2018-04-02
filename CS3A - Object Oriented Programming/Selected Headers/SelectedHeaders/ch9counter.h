#ifndef CH9COUNTER_H
#define CH9COUNTER_H

class Counter
{
public:
    Counter();
    Counter(int num);

    //Accessors
    int gettotal();
    //Mutators
    void incr1();
    void incr10();
    void incr100();
    void incr1000();

    bool overflow();

private:
    int total;
};

#endif // CH9COUNTER_H
