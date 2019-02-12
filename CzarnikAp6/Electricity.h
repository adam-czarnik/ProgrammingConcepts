// Electricity.h
// Adam Czarnik
// December 3, 2018
//
// Header file for Electricity class, derived from base polluter class. Inherits
// only the getCarbonFootprint function to print carbon data.

#ifndef Electricity_h
#define Electricity_h

#include "Polluter.h"
#include <string>
#include <iostream>

using namespace std;

class Electricity: public Polluter {
private:
    double billPerMonth;
    double pricePerKwh;
    double electricityEmissionsFactor;
    
public:
    Electricity(double);
    void getCarbonFootprint();
};

#endif

