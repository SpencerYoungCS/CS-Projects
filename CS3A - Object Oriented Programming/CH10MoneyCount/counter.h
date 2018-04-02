#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
public:
    Counter();
    Counter(int newi);

    void reset();
    void incr1();
    void incr10();
    void incr100();
    void incr1000();

    int geti();

    char keys(char key);

    bool overflow();



private:
    int i;
};

#endif // COUNTER_H
