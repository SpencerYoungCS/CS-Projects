#ifndef USEFUL_H  // Prevent duplicate definition
#define USEFUL_H

#include <iostream>    // Provides cout
#include <string>      // Provides string class
#include "bintree.h"   // Provides the binary tree node functions
#include <cassert>    // Provides assert
#include <cctype>     // Provides toupper
#include <cstdlib>    // Provides rand, RAND_MAX
#include <fstream>


using namespace std;
    double random_fraction( );
    double random_real(double low, double high);
    void display(double x);
    void eat_line( );
    bool inquire(const char query[ ]);

#endif
