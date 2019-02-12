// Polluter.cpp
// Adam Czarnik
// December 3, 2018
//
// This file contains the definition of the polluter class, an abstract base
// class. It has a single virtual function.

#include "Polluter.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Polluter::Polluter() {
    carbonFootprint = 0;
}

void Polluter::getCarbonFootprint() {
    cout << setw(50) << "CO2 EMISSIONS IN POUNDS:";
    cout << carbonFootprint << endl;
}
