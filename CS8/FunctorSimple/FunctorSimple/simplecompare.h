#ifndef SIMPLECOMPARE_H
#define SIMPLECOMPARE_H

class Greater
{
public:
    bool operator ()(int left, int right){
        return left>right;
    }
};

class Less
{
public:
    bool operator()(int left, int right){
        return left < right;
    }
};

#endif // SIMPLECOMPARE_H
