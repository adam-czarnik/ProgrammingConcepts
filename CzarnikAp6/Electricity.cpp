// Electricity.cpp
// Adam Czarnik
// December 3, 2018
//
// Driver file for Electricity class, derived from base polluter class. Inherits
// only printing function for carbon data.

#include "Electricity.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Electricity::Electricity(double bill) {
    billPerMonth = bill;
    pricePerKwh = 0.2;
    electricityEmissionsFactor = 1.37;
    
}

void Electricity::getCarbonFootprint() {
    //calculate carbon footprint, CO2 emissions in pounds
    carbonFootprint = ( billPerMonth / pricePerKwh )
    * electricityEmissionsFactor * 12;
    
    //print out data nicely formatted
    cout << setfill('-') << setw(50) << "-" << endl;
    cout << left << setfill(' ') << setw(50) << "Carbon Footprint:";
    cout << "Electricity" << endl;
    cout << setw(50) << "Average Electric Bill per Month:";
    cout << billPerMonth << endl;
    cout << setw(50) << "Price per KWH:";
    cout << pricePerKwh << endl;
    cout << setw(50) << "Electricity Emissions Factor:";
    cout << electricityEmissionsFactor << endl << endl;
    Polluter::getCarbonFootprint();
    cout << setfill('-') << setw(50) << "-" << endl;
    cout << endl;
}


