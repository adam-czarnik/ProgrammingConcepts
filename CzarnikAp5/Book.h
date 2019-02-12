//
//  Book.h
//  CzarnikAp5
//
//  Created by Adam Czarnik on 11/6/18.
//  Copyright © 2018 Adam Czarnik. All rights reserved.
//

#ifndef Book_h
#define Book_h

#include <stdio.h>
#include <string>

using namespace std;

class Book {
    
private:
    string title;
    int width;
    int height;
    int area;
    int pages;
    string authorLastName;
    string authorFirstName;
    bool loaned;
    string borrowerLastName;
    string borrowerFirstName;
    string returnDate;
    
public:
    //sets and gets for everything above, and a display
    Book(string = "", int = 0, int = 0, int = 0, string = "", string = "");
    void setTitle(string);
    string getTitle();
    void setWidth(int);
    int getWidth();
    void setHeight(int);
    int getHeight();
    int getArea();
    void setPages(int);
    int getPages();
    void setAuthorLastName(string);
    string getAuthorLastName();
    void setAuthorFirstName(string);
    string getAuthorFirstName();
    void display();
    bool loanStatus();
    void loanedOut();
    void returned();
    void setBorrowerLastName(string);
    string getBorrowerLastName();
    void setBorrowerFirstName(string);
    string getBorrowerFirstName();
    void setReturnDate(string);
    string getReturnDate();
    
};

#endif /* Book_h */
