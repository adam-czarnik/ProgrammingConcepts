/********
 p3.cpp
 by Adam Czarnik
 October 5, 2018
 
 This program allows a user to read data about New York Times bestseller
 list and search the data. You can search by date, author, and title.
 
 ********/

#include <iostream>
#include <cmath> //math library
#include <vector> //vector functions
#include <fstream>
#include <cstring> //string functions
#include <string>
#include <algorithm> //to lowercase string
using namespace std;

//function prototypes
int fillVectors(vector<string>&, vector<string>&, vector<string>&,
                 vector<string>&, vector<string>&);
char menu();
void inYearRange(vector<string>, vector<string>, vector<string>,
                 vector<string>, vector<string>);
void inMonthAndYear(vector<string>, vector<string>, vector<string>,
                    vector<string>, vector<string>);
void searchAuthor(vector<string>, vector<string>, vector<string>,
                  vector<string>, vector<string>);
void searchTitle(vector<string>, vector<string>, vector<string>,
                 vector<string>, vector<string>);
void printBook(int, vector<string>, vector<string>, vector<string>,
               vector<string>, vector<string>);


int main() {
    //define vectors to hold data, book data kept in same spot accross vectors
    vector<string> titles(1);
    vector<string> authors(1);
    vector<string> publishers(1);
    vector<string> dates(1);
    vector<string> categories(1);
    
    //call function to fill Vectors with data
    int tmp = fillVectors(titles, authors, publishers, dates, categories);
    
    //if file could not open, exit program
    if (tmp == 1) {
        return 1;
    }
    
    //print menu until valid choice is entered, or q entered
    char choice;
    choice = menu();
    choice = tolower(choice);
    
    //until q is entered, perform menu option selected
    while (choice != 'q') {
        if (choice == 'a') {
            inYearRange(titles, authors, publishers, dates, categories);
        } else if (choice == 'b') {
            inMonthAndYear(titles, authors, publishers, dates, categories);
        } else if (choice == 'c') {
            searchAuthor(titles, authors, publishers, dates, categories);
        } else if (choice == 'd') {
            searchTitle(titles, authors, publishers, dates, categories);
        }
        
        //after performing action, ask for another
        choice = menu();
        choice = tolower(choice);
    }
    
    return 0;
    
}

//function to fill given vectors with data from file
int fillVectors(vector<string> &t, vector<string> &a, vector<string> &p,
                vector<string> &d, vector<string> &c) {
    
    //fill vectors with data
    ifstream bookData("bestsellers.txt", ios::in);
    
    //error case, return 1 to indicate could not open
    if (!bookData) {
        cout << "Could not open file." << endl;
        return 1;
    }
    
    //temporarily hold next string from file
    string tmp;
    
    //prime read then while loop to get data
    getline(bookData, tmp, '\t');
    t.push_back(tmp);
    while (!bookData.eof()) {
        getline(bookData, tmp, '\t');
        a.push_back(tmp);
        getline(bookData, tmp, '\t');
        p.push_back(tmp);
        getline(bookData, tmp, '\t');
        d.push_back(tmp);
        getline(bookData, tmp);
        c.push_back(tmp);
        getline(bookData, tmp, '\t');
        t.push_back(tmp);
    }
    
    return 0;
}

//function to print menu and return choice as a char
char menu() {
    //give a bit of space above menu for clarity, and a clear seperator
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "What do you want to do?" << endl;
    cout << "a. Display all books for a given year range" << endl;
    cout << "b. Display all books for a given month and year" << endl;
    cout << "c. Search for a given author" << endl;
    cout << "d. Search for a title" << endl;
    cout << "q. Quit the program" << endl;
    cout << "Choice: ";
    
    //prime read then repeat asking if necessary until valid choice
    char choice;
    cin >> choice;
    choice = tolower(choice);
    while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' &&
           choice != 'q') {
        cout << "Not a valid choice. Pick again." << endl;
        cout << "Choice: ";
        cin >> choice;
        cin.ignore('\n');
        choice = tolower(choice);
    }
    
    return choice;
}

//funciton to search for books in a given year range
void inYearRange(vector<string> t, vector<string> a, vector<string> p,
                 vector<string> d, vector<string> c) {
    string start, unstart;
    cout << "Searching by year..." << endl;
    cout << "First year: ";
    cin >> start;
    cout << "Last year: ";
    cin >> unstart;
    
    //temporary boolean to determine if nothing printed
    bool tmp = false;
    
    //read through each item in date vector, compare to given years
    for (int i=0; i<d.size(); i++) {
        int fslash, sslash;
        string year;
        fslash = d.at(i).find("/");
        sslash = d.at(i).find("/",fslash+1);
        year = d.at(i).substr(sslash+1,d.at(i).length());
        if (year >= start && year <= unstart) {
            printBook(i, t, a, p, d, c);
            tmp = true;
        }
    }
    
    //if nothing printed, output that
    if (!tmp) {
        cout << "No books found between " << start << " and " << unstart
        << "." << endl;
    }
    
}

//function to search for books in a given month/year
void inMonthAndYear(vector<string> t, vector<string> a, vector<string> p,
                    vector<string> d, vector<string> c) {
    string month, year;
    cout << "Searching by month and year..." << endl;
    cout << "Month (as a number): ";
    cin >> month;
    cout << "Year: ";
    cin >> year;
    
    //temporary boolean to determine if nothing printed
    bool tmp = false;
    
    //read through each item in date vector, compare to given date
    for (int i=0; i<d.size(); i++) {
        int fslash, sslash;
        string m, y;
        fslash = d.at(i).find("/");
        m = d.at(i).substr(0,fslash);
        sslash = d.at(i).find("/",fslash+1);
        y = d.at(i).substr(sslash+1,d.at(i).length());
        if (m == month && y == year) {
            printBook(i, t, a, p, d, c);
            tmp = true;
        }
    }
    
    //if nothing printed, output that
    if (!tmp) {
        cout << "No books found in month #" << month << ", "
        << year << "." << endl;
    }
    
}

//function to search for a given author
void searchAuthor(vector<string> t, vector<string> a, vector<string> p,
                  vector<string> d, vector<string> c) {
    string author;
    cout << "Searching by author..." << endl;
    cout << "Author: ";
    cin.ignore(80,'\n');
    getline(cin, author);
    
    //temporary boolean to determine if nothing printed
    bool tmp = false;
    
    //read through each item in author vector, compare to given author
    for (int i=0; i<a.size(); i++) {
        transform(author.begin(), author.end(), author.begin(), ::toupper);
        string na;
        na = a.at(i);
        std::transform(na.begin(), na.end(), na.begin(), ::toupper);
        if (author.compare(na) == 0) {
            printBook(i, t, a, p, d, c);
            tmp = true;
        }
    }
    
    //if nothing printed, output that
    if (!tmp) {
        cout << "No books found for author " << author << "." << endl;
    }
}

//function to search for a given title
void searchTitle(vector<string> t, vector<string> a, vector<string> p,
                 vector<string> d, vector<string> c) {
    string title;
    cout << "Searching by title..." << endl;
    cout << "Title: ";
    cin.ignore(80,'\n');
    getline(cin, title);
    
    //temporary boolean to determine if nothing printed
    bool tmp = false;
    
    //read through each item in author vector, compare to given author
    for (int i=0; i<t.size(); i++) {
        transform(title.begin(), title.end(), title.begin(), ::toupper);
        string nt;
        nt = t.at(i);
        std::transform(nt.begin(), nt.end(), nt.begin(), ::toupper);
        if (title.compare(nt) == 0) {
            printBook(i, t, a, p, d, c);
            tmp = true;
        }
    }
    
    //if nothing printed, output that
    if (!tmp) {
        cout << "No books found for title " << title << "." << endl;
    }
}

//function to print book info given an index for all vectors
void printBook(int idx, vector<string> t, vector<string> a, vector<string> p,
               vector<string> d, vector<string> c) {
    cout << t.at(idx) << " by " << a.at(idx) << " (" << d.at(idx) << ")";
    cout << endl;
}
