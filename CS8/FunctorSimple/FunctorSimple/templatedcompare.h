#ifndef TEMPLATEDCOMPARE_H
#define TEMPLATEDCOMPARE_H

template <typename T>
class Bigger
{
public:
    bool operator()(const T& left, const T& right){
        return left > right;
    }
};

template <typename T>
class Smaller
{
public:
    bool operator()(const T& left, const T& right){
        return left < right;
    }
};

#endif // TEMPLATEDCOMPARE_H
