#ifndef LinkList_h
#define LinkList_h

#include <iostream>
#include "ListNode.h"

using namespace std;

class LinkList{
public:
    LinkList() {
        head = nullptr;
    }
    void remove(Book);
    void display();
    void add(Book);
    ~LinkList();
    void insert(Book);
    void insertLoaner(Book);
    Book& find(string);
    bool exceptional(string);
    int count();
    int countShelf();
    Book getBook(int);
private:
    ListNode * head;
};

#endif
