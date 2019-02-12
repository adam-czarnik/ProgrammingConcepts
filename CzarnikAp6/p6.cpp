// p6.cpp
// Adam Czarnik
// December 3, 2018
//
// A main driver file that creates three polluter objects of various derived
// types, and adds them to a vector. Then it iterates through the vector
// polymorphically, printing each one using the inherited getCarbonFootprint
// method derived from the base Polluter class.

//#include "Polluter.h"
#include "AirTravel.h"
#include "Electricity.h"
#include "Vehicles.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    vector<Polluter *> polluters;
    cout << endl;
    
    //creating the three objects and placing them in the vector
    cout << "Creating Air Travel Polluter object." << endl;
    cout << "How many miles per year? " << endl;
    int miles;
    cin >> miles;
    polluters.push_back(new AirTravel(miles));
    cout << endl;
    cout << "Creating Electricity object." << endl;
    cout << "What is the monthly bill cost? " << endl;
    int bill;
    cin >> bill;
    polluters.push_back(new Electricity(bill));
    cout << endl;
    cout << "Creating Vehicle object." << endl;
    cout << "How many miles per week? " << endl;
    int milesW;
    cin >> milesW;
    cout << "What is the fuel efficiency? " << endl;
    double efficiency;
    cin >> efficiency;
    polluters.push_back(new Vehicles(milesW, efficiency));
    cout << endl;
    
    //iterate through polymorphically and print
    for (Polluter *nextPolluter:polluters) {
        nextPolluter->getCarbonFootprint();
    }
    
    return 0;
}
