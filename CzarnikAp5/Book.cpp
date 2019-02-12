//
//  Book.cpp
//  CzarnikAp5
//
//  Created by Adam Czarnik on 11/6/18.
//  Copyright © 2018 Adam Czarnik. All rights reserved.
//
// .cpp file for all the functions in the book object, used to manage the
// shelf.

#include <iostream>

#include "Book.h"

Book::Book(string t, int w, int h, int p, string l, string f) {
    title = t;
    width = w;
    height = h;
    area = width * height;
    pages = p;
    authorLastName = l;
    authorFirstName = f;
    loaned = false;
    borrowerLastName = "";
    borrowerFirstName = "";
    returnDate = "";
}

void Book::setTitle(string t) {
    title = t;
}

string Book::getTitle() {
    return title;
}

void Book::setWidth(int w) {
    width = w;
}

int Book::getWidth() {
    return width;
}

void Book::setHeight(int h) {
    height = h;
}

int Book::getHeight() {
    return height;
}

int Book::getArea() {
    return area;
}

void Book::setPages(int p) {
    pages = p;
}

int Book::getPages() {
    return pages;
}

void Book::setAuthorLastName(string l) {
    authorLastName = l;
}

string Book::getAuthorLastName() {
    return authorLastName;
}

void Book::setAuthorFirstName(string f) {
    authorFirstName = f;
}

string Book::getAuthorFirstName() {
    return authorFirstName;
}

void Book::display() {
    cout << title << " by " << authorFirstName << " " << authorLastName;
    cout << " (" << height << "x" << width << ", " << pages << " p)" << endl;
}

bool Book::loanStatus() {
    return loaned;
}

void Book::loanedOut() {
    loaned = true;
}

void Book::returned() {
    loaned = false;
}

void Book::setBorrowerLastName(string bl) {
    borrowerLastName = bl;
}

string Book::getBorrowerLastName() {
    return borrowerLastName;
}

void Book::setBorrowerFirstName(string bf) {
    borrowerFirstName = bf;
}

string Book::getBorrowerFirstName() {
    return borrowerFirstName;
}

void Book::setReturnDate(string d) {
    returnDate = d;
}

string Book::getReturnDate() {
    return returnDate;
}
