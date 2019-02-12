//
//  main.cpp
//  CzarnikAp5
//
//  Created by Adam Czarnik on 11/6/18.
//  Copyright © 2018 Adam Czarnik. All rights reserved.
//
// Program used to manage a bookshelf, including adding, loaning, and returning.
// Input is a file, and books on the shelf are sorted by cover area, then
// number of pages.

#include <iostream>
#include <fstream>

#include "Book.h"
#include "LinkList.h"

int main() {
    //ask for a filename to open as input data
    ifstream inFile;
    cout << "File to open: ";
    string filename;
    cin >> filename;
    
    //attempt to open the file
    cout << "Opening " << filename << "..." << endl;
    inFile.open(filename);
    if (!inFile.is_open()) {
        cout << "Error opening " << filename << endl;
        return 0;
    }
    if (inFile.is_open()) {
        cout << "Opened file " << filename << endl;
    }
    
    //create the two linklists of books
    LinkList shelf;
    LinkList loan;
    
    int numOfRecords;
    inFile >> numOfRecords;
    
    //run through each entry record in file until eof
    for (int i=0; i<numOfRecords; i++) {
        string recordType;
        inFile >> recordType;
        if (recordType == "A") {
            int width;
            int height;
            int pages;
            string authorl;
            string authorf;
            string title;
            inFile >> width >> height >> pages >> authorl >> authorf;
            getline(inFile, title);
            
            //create book b with inputs
            Book b(title, width, height, pages, authorl, authorf);
            shelf.insert(b);
            
        } else if (recordType == "L") {
            string borrowerl;
            string borrowerf;
            string month;
            string day;
            string year;
            string title;
            inFile >> borrowerl >> borrowerf >> month >> day >> year;
            getline(inFile, title);
            string date = year + "/" + month + "/" + day;
            
            //find existing book on shelf
            bool isOnShelf = shelf.exceptional(title);
            if (isOnShelf) {
                Book& b = shelf.find(title);
                
                if (b.loanStatus() == false) {
                    b.setBorrowerFirstName(borrowerf);
                    b.setBorrowerLastName(borrowerl);
                    b.setReturnDate(date);
                    b.loanedOut();
                    loan.add(b);
                } else {
                    //already loaned out
                    //cout << title << " ALREADY LOANED OUT." << endl;
                }
            } else {
                //not in library
                //cout << title << " NOT IN LIBRARY." << endl;
            }
            
        } else if (recordType == "R") {
            string title;
            getline(inFile, title);
            Book& b = shelf.find(title);
            b.returned();
            Book& old = loan.find(title);
            loan.remove(old);
        }
    }
    
    loan.display();
    
    //putting data into output files
    ofstream outShelf; // Output file stream
    ofstream outLoan;
    
    outShelf.open("bookshelf.txt"); // Open file
    outLoan.open("booksOnLoan.txt");
    
    if (!outShelf.is_open()) {
        cout << "Could not open file bookshelf.txt." << endl;
        return 1;
    }
    if (!outLoan.is_open()) {
        cout << "Could not open file booksOnLoan.txt." << endl;
        return 1;
    }
    
    //count # of books on shelf, output to file
    int totalBooks = shelf.count();
    int booksOnShelf = shelf.countShelf();
    outShelf << booksOnShelf << endl;
    int numOnList = 1; //number preceeding title in outputfile
    for (int i=0; i<totalBooks; i++) {
        Book b = shelf.getBook(i);
        if (b.loanStatus() == false) {
            outShelf << numOnList << ". " << b.getTitle() << " by " << b.getAuthorFirstName()
            << " " << b.getAuthorLastName() << " (" << b.getWidth() << "x"
            << b.getHeight() << ", " << b.getPages() << " p)" << endl;
            numOnList++;
        }
    }
    
    //count # of books on loan, output to file
    int booksOnLoan = loan.count();
    outLoan << booksOnLoan << endl;
    string lastDate, currentDate; //temp strings for formatting under same date
    Book b = loan.getBook(0);
    lastDate = b.getReturnDate();
    outLoan << b.getReturnDate() << endl;
    outLoan << "1. " << b.getTitle() << " borrowed by ";
    outLoan << b.getBorrowerFirstName() << " " << b.getBorrowerLastName();
    outLoan << endl;
    for (int i=1; i<booksOnLoan; i++) {
        Book b = loan.getBook(i);
        currentDate = b.getReturnDate();
        if (!(currentDate == lastDate)) {
            outLoan << b.getReturnDate() << endl;
        }
        outLoan << i+1 << ". " << b.getTitle() << " borrowed by ";
        outLoan << b.getBorrowerFirstName() << " " << b.getBorrowerLastName();
        outLoan << endl;
        lastDate = currentDate;
    }
    
    outShelf.close();
    outLoan.close();
    
    return 0;
}
