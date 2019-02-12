/********
 p2.cpp
 by Adam Czarnik
 September 17, 2018
 
 This file is creates a vending machine program that takes inputted change
 and offers various food items for sale. After a selection is made, a
 price will be given and if change is necessary it will be dispensed. If
 change is not available it will give instructions.
 
********/
#include <iostream>
#include <cmath> //math library
#include <iomanip> //includes setprecision
using namespace std;

//prototypes
void newSection();
void getStock(int&, int&, int&, int&);
void printStock(int, int, int, int);
char mainMenu();
double getPrice(char);
void needMoney(double&, int&, int&, int&, int&);
void giveChange(double&, int&, int&, int&, int&, int&, int&);

int main (void) {
    
    //VM = vending machine
    newSection();
    cout << "Hi! Welcome to the vending machine." << endl;
    
    //declaring variables for change in machine
    int ones;
    int quarters;
    int dimes;
    int nickels;
    
    getStock(ones, quarters, dimes, nickels);
    
    cout << "To confirm, ";
    printStock(ones, quarters, dimes, nickels);
    
    //run process
    int run = 1;
    while (run) {
        char selection;
        selection = mainMenu();
        
        //verify selection, gets price, asks for money
        double cost;
        if (selection != 'q') {
            cost = getPrice(selection);
        } else {
            run = 0;
            cout << endl;
            printStock(ones, quarters, dimes, nickels);
        }
        
        if (run && cost != 0.0) {
            //print price of item, and change input menu
            newSection();
            cout << fixed << setprecision(2);
            cout << "That item costs: $" << cost << endl;
            cout << endl;
            
            //asks for change until no more is needed
            double moneyNeeded = cost;
            while (moneyNeeded > 0.0 && cost != 0.0) {
                needMoney(moneyNeeded, ones, quarters, dimes, nickels);
            }
            
            if (moneyNeeded != 0) {
                newSection();
                cout << "Dispensing change: $";
                cout << moneyNeeded << endl;
            } else {
                newSection();
                cout << "No change needed, exact amount paid." << endl;
            }
            
            //variables for change to be dispensed
            int dQ = 0;
            int dD = 0;
            int dN = 0;
            
            //giveChange requires a positive amount
            moneyNeeded *= -1;
            giveChange(moneyNeeded, dQ, dD, dN, quarters, dimes, nickels);
            
            //print change to be given in terms of coins
            if (dQ > 0) {
                cout << dQ << " Quarters" << endl;
            }
            if (dD > 0) {
                cout << dD << " Dimes" << endl;
            }
            if (dN > 0) {
                cout << dN << " Nickels" << endl;
            }
            
            cout << endl;
            cout << "Dispensing item..." << endl;
            
            cout << endl;
            printStock(ones, quarters, dimes, nickels);
            
        }
    }
}

void newSection() {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "|----------------------------|" << endl;
    cout << "|----------------------------|" << endl;
}

void getStock(int& o, int& q, int& d, int& n) {
    cout << "Starting # of QUARTERS: ";
    cin >> q;
    cout << "Starting # of DIMES: ";
    cin >> d;
    cout << "Starting # of NICKELS: ";
    cin >> n;
    cout << endl;
    o = 0;
}

void printStock(int o, int q, int d, int n) {
    cout << "Money currently in machine: " << endl;
    cout << o << " One-Dollar Bills" << endl;
    cout << q << " Quarters" << endl;
    cout << d << " Dimes" << endl;
    cout << n << " Nickels" << endl;
}

char mainMenu() {
    //print main info, including available change for refrence
    newSection();
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
    return selection;
}

double getPrice(char s) {
    double price;
    if (s == 'a') {
        price = 1.00;
    } else if (s == 'b') {
        price = 1.35;
    } else if (s == 'c') {
        price = 5.00;
    } else if (s == 'd') {
        price = 0.50;
    } else if (s == 'e') {
        price = 1.50;
    } else if (s == 'f') {
        price = 2.15;
    } else {
        
        cout << "That's not a choice!" << endl;
        price = 0.0;
    }
    return price;
}

void needMoney(double& moneyNeeded, int& o, int& q, int& d, int& n) {
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
        n++;
    } else if (coinInserted == 'b') {
        moneyNeeded = moneyNeeded - .1;
        d++;
    } else if (coinInserted == 'c') {
        moneyNeeded = moneyNeeded - .25;
        q++;
    } else if (coinInserted == 'd') {
        moneyNeeded = moneyNeeded - 1;
        o++;
    } else {
        cout << "That's not a choice!" << endl;
    }
}

void giveChange(double& moneyNeeded, int& dQ, int& dD, int& dN, int& q, int& d, int& n) {
    while (moneyNeeded > 0.0) {
        if (moneyNeeded >= 0.25 && q > 0) {
            dQ++;
            q--;
            moneyNeeded = moneyNeeded - 0.25;
        } else if (moneyNeeded >= 0.10 && d > 0) {
            dD++;
            d--;
            moneyNeeded = moneyNeeded - 0.10;
        } else if (moneyNeeded >= 0.05 && n > 0) {
            dN++;
            n--;
            moneyNeeded = moneyNeeded - 0.05;
        } else if (moneyNeeded > 0.0 && n == 0) {
            cout << endl;
            cout << "Not enough change in the machine." << endl;
            cout << "Please ask the store manager for: $";
            cout << moneyNeeded << endl;
            break;
        } else {
            break;
        }
    }
}

