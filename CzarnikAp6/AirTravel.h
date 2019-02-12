// AirTravel.h
// Adam Czarnik
// December 3, 2018
//
// Header file for Air Travel class, derived from base polluter class. Inherits
// only a single function to print carbon data.

#ifndef AirTravel_h
#define AirTravel_h

#include "Polluter.h"
#include <string>
#include <iostream>

using namespace std;

class AirTravel: public Polluter {
private:
    int milesPerYear;
    double emissionsPerMile;
    double wellToPumpFactor;
    double atmosphericRadiativeFactor;
    
public:
    AirTravel(int);
    void getCarbonFootprint();
};

#endif
