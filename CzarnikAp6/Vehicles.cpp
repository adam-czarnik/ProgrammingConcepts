// Vehicles.cpp
// Adam Czarnik
// December 3, 2018
//
// Driver file for Vehicles class, derived from base polluter class. Includes
// functions for vehicle class, including getCarbonFootprint, derived from
// the funciton in base class.

#include "Vehicles.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Vehicles::Vehicles(int miles, double effinciency) {
    milesPerWeek = miles;
    fuelEfficiency = effinciency;
    poundsOfCo2Emitted = 19.4;
    emissionsOfGreenhouseGasses = (100/95);
}

void Vehicles::getCarbonFootprint() {
    //calculate carbon footprint, CO2 emissions in pounds
    carbonFootprint = (milesPerWeek * 52) / fuelEfficiency
    * poundsOfCo2Emitted * emissionsOfGreenhouseGasses;
    
    //print out data nicely formatted
    cout << setfill('-') << setw(50) << "-" << endl;
    cout << left << setfill(' ') << setw(50) << "Carbon Footprint:";
    cout << "Vehicles" << endl;
    cout << setw(50) << "Miles Driven per Week:";
    cout << milesPerWeek << endl;
    cout << setw(50) << "Fuel Efficiency per Vehicle:";
    cout << fuelEfficiency << endl;
    cout << setw(50) << "Pounds of CO2 Emitted per Gallon:";
    cout << poundsOfCo2Emitted << endl;
    cout << setw(50) << "Emissions of Greenhouse Gasses Other Than CO2:";
    cout << emissionsOfGreenhouseGasses << endl << endl;
    Polluter::getCarbonFootprint();
    cout << setfill('-') << setw(50) << "-" << endl;
    cout << endl;
}


