// Vehicles.h
// Adam Czarnik
// December 3, 2018
//
// Header file for Vehicles class, derived from base polluter class. Inherits
// one function, getCarbonFootprint, from base class.

#ifndef Vehicles_h
#define Vehicles_h

#include "Polluter.h"
#include <string>
#include <iostream>

using namespace std;

class Vehicles: public Polluter {
private:
    int milesPerWeek;
    double fuelEfficiency;
    double poundsOfCo2Emitted;
    double emissionsOfGreenhouseGasses;
    
public:
    Vehicles(int, double);
    void getCarbonFootprint();
};

#endif

