/********
p1.cpp
by Adam Czarnik
September 10, 2018

This file is creates a vending machine program that takes inputted change
and offers various food items for sale. After a selection is made, a
price will be given and if change is necessary it will be dispensed. If
change is not available it will give instructions.

********/
#include <iostream>
#include <cmath> //math library
#include <iomanip> //includes setprecision
using namespace std;

int main (void) {

	//VM = vending machine
	
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "|----------------------------|" << endl;
        cout << "|----------------------------|" << endl;
	cout << "Hi! Welcome to the vending machine." << endl;
    
    //declaring variables for change in machine
    int nickels;
    int dimes;
    int quarters;
    int ones;
	
	cout << "Starting # of QUARTERS: ";
	cin >> quarters;
	cout << "Starting # of DIMES: ";
	cin >> dimes;
	cout << "Starting # of NICKELS: ";
	cin >> nickels;
	cout << endl;
	ones = 0;
	cout << "To confirm, the machine has:" << endl;
	cout << quarters << " Quarters" << endl;
	cout << dimes << " Dimes" << endl;
	cout << nickels << " Nickels" << endl;
	cout << ones << " One-Dollar Bills" << endl;

	//run process
	int run = 1;
	while (run) {

        //print main info, including available change for refrence
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "|----------------------------|" << endl;
        cout << "|----------------------------|" << endl;
        cout << "Vending Machine" << endl;
        
        //print food items available and price
        cout << "Please select a food item to buy, or enter q to quit" << endl;
        cout << "a. Cheetos $1.00" << endl;
        cout << "b. Chips Ahoy! Chewey $1.35" << endl;
        cout << "c. Bottle of Water $5.00" << endl;
        cout << "d. Ramen $0.50" << endl;
        cout << "e. Goldfish $1.50" << endl;
        cout << "f. Strawberry-Kiwi Snapple $2.15" << endl;
        cout << "q. Quit the program" << endl;
        
        //ask for choice from user
        cout << "What would you like to buy? ";
        char selection;
        cin >> selection;
        
        //verify selection, gets price, asks for money
        double price = 0.0;
        if (selection == 'a') {
            price = 1.00;
        } else if (selection == 'b') {
            price = 1.35;
        } else if (selection == 'c') {
            price = 5.00;
        } else if (selection == 'd') {
            price = 0.50;
        } else if (selection == 'e') {
            price = 1.50;
        } else if (selection == 'f') {
            price = 2.15;
        } else if (selection == 'q') {
            run = 0;
	    cout << endl;
	    cout << "Money left in machine: " << endl;
            cout << quarters << " Quarters" << endl;
            cout << dimes << " Dimes" << endl;
            cout << nickels << " Nickels" << endl;
            cout << ones << " One-Dollar Bills" << endl;
        } else {
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "|----------------------------|" << endl;
            cout << "|----------------------------|" << endl;
            cout << "That's not a choice!" << endl;
	    price = 0.0;
        }
        
        if (run && price != 0.0) {
            //print price of item, and change input menu
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "|----------------------------|" << endl;
            cout << "|----------------------------|" << endl;
	    cout << fixed << setprecision(2);
            cout << "That item costs: $" << price << endl;
            cout << endl;
        
            //asks for change until no more is needed
            double moneyNeeded = price;
            while (moneyNeeded > 0 && price != 0.0) {
                cout << endl;
                cout << fixed << setprecision(2);
                cout << "You still owe $" << moneyNeeded << endl;
                cout << "Please select a coin to insert." << endl;
                cout << "a. Nickel" << endl;
                cout << "b. Dime" << endl;
                cout << "c. Quarter" << endl;
		cout << "d. One-Dollar Bill" << endl;
                char coinInserted;
                cout << "Money: ";
                cin >> coinInserted;
                if (coinInserted == 'a') {
                    moneyNeeded = moneyNeeded - .05;
		    nickels++;
                } else if (coinInserted == 'b') {
                    moneyNeeded = moneyNeeded - .1;
                    dimes++;
		} else if (coinInserted == 'c') {
                    moneyNeeded = moneyNeeded - .25;
                    quarters++;
		} else if (coinInserted == 'd') {
		    moneyNeeded = moneyNeeded - 1;
		    ones++;
		} else {
                    cout << "That's not a choice." << endl;
                }	
            }
	if (moneyNeeded != 0) {
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "|----------------------------|" << endl;
		cout << "|----------------------------|" << endl;
		cout << "Dispensing change: $";
		cout << moneyNeeded << endl;
	} else {
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "|----------------------------|" << endl;
		cout << "|----------------------------|" << endl;
		cout << "No change needed, exact amount paid." << endl;
	}

	int dispenseQ = 0;
        int dispenseD = 0;
        int dispenseN = 0;
	double changeNeeded = moneyNeeded * -1;
	while (changeNeeded > 0) {
		if (changeNeeded >= 0.25 && quarters > 0) {
			dispenseQ++;
			quarters--;
			changeNeeded = changeNeeded - .25;
		} else if (changeNeeded >= 0.10 && dimes > 0) {
			dispenseD++;
			dimes--;
			changeNeeded = changeNeeded - .1;
		} else if (changeNeeded > 0 && nickels > 0) {
			dispenseN++;
			nickels--;
			changeNeeded = changeNeeded - .05;
		} else if (changeNeeded != 0 && nickels == 0) {
			cout << endl;
			cout << "Please ask the store manager for: $";
			cout << changeNeeded << endl;
			changeNeeded = 0.0;
		}
	}	
	if (dispenseQ > 0) {
		cout << dispenseQ << " Quarters" << endl;
	}
	if (dispenseD > 0) {
		cout << dispenseD << " Dimes" << endl;
	}
	if (dispenseN > 0) {
		cout << dispenseN << " Nickels" << endl;
	}

	cout << endl;
	cout << "Dispensing item..." << endl; 

	cout << endl;
	cout << "Money left in machine: " << endl;
	cout << quarters << " Quarters" << endl;
	cout << dimes << " Dimes" << endl;
	cout << nickels << " Nickels" << endl;
	cout << ones << " One-Dollar Bills" << endl;
	
        }
	}
}
