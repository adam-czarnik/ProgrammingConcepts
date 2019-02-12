// Polluter.h
// Adam Czarnik
// December 3, 2018
//
// Base polluter class for which the other three are derived from. Includes
// only a single base function to display carbon footprint number.

#ifndef Polluter_h
#define Polluter_h

#include <string>
#include <iostream>

using namespace std;

class Polluter {
protected:
    double carbonFootprint;
    
public:
    Polluter();
    virtual void getCarbonFootprint();
    
};

#endif
