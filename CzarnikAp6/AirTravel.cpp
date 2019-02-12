// AirTravel.cpp
// Adam Czarnik
// December 3, 2018
//
// Driver file for Air Travel class, derived from base polluter class. Inherits
// only one function from main polluter class, to print carbon data.

#include "AirTravel.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

AirTravel::AirTravel(int miles) {
    milesPerYear = miles;
    emissionsPerMile = 223;
    wellToPumpFactor = 1.2;
    atmosphericRadiativeFactor = 1.9;
}

void AirTravel::getCarbonFootprint() {
    //calculate carbon footprint, CO2 emissions in pounds
    carbonFootprint = milesPerYear * emissionsPerMile * wellToPumpFactor
    * atmosphericRadiativeFactor * 0.0022;
    
    //print out data nicely formatted
    cout << setfill('-') << setw(50) << "-" << endl;
    cout << left << setfill(' ') << setw(50) << "Carbon Footprint:";
    cout << "Air Travel" << endl;
    cout << setw(50) << "Air Miles Traveled Per Year:";
    cout << milesPerYear << endl;
    cout << setw(50) << "Average Emissions Per Mile:";
    cout << emissionsPerMile << endl;
    cout << setw(50) << "Indirect Well-To-Pump Factor:";
    cout << wellToPumpFactor << endl;
    cout << setw(50) << "Indirect Atmospheric Radiative Forcing Factor:";
    cout << atmosphericRadiativeFactor << endl << endl;
    Polluter::getCarbonFootprint();
    cout << setfill('-') << setw(50) << "-" << endl;
    cout << endl;
}

