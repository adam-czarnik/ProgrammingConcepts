#include <iostream>
#include "LinkList.h"
#include "ListNode.h"
#include "Book.h"

using namespace std;

void LinkList::remove(Book value)
{  cout << "Removing node with value: " << value.getTitle() << endl;
    ListNode * current = head;
    ListNode * previous;
    if(current == nullptr)
        cout << "ERROR: List List empty" << endl;
    else
    {
        while (current !=nullptr && current->getValue().getTitle() != value.getTitle())
        {    previous = current; // save current
            current = current->getNext();
        }
        
        if (current == nullptr)
            cout <<" value " << value.getTitle() << "not found" << endl;
        else
            if (current == head)//first one is being removed
            { head = current->getNext();
                delete current;
            }
            else
            {previous->setNext(current->getNext());
                delete current;
            }
    }
}// end of method

void LinkList::display()
{ ListNode * current = head;
    if (current == nullptr)
        cout << "Link List is empty" << endl;
    else
        // iterate over the list and display each value
    { while(current != nullptr && !(current->getValue().loanStatus()))
    {cout << current->getValue().getTitle() << endl;
        current = current->getNext();
    } // end of while loop
    } // end of else
    
}// end of function

void LinkList::add(Book value) // adding by cover area then # of pages
{
    ListNode * current = head;
    if (current == nullptr) // create a newNode
    { ListNode *newNode = new ListNode;
        newNode->setValue(value);
        newNode->setNext(nullptr);
        head=newNode; }
    else
    {// iterate until we get to the end of the list
        while(current->getNext() != nullptr)
            current = current->getNext();
        // now create a new ListNode
        ListNode * newNode = new ListNode;
        newNode->setValue(value);
        newNode->setNext(nullptr);
        current->setNext(newNode); }  // end else
} // end of method add

LinkList::~LinkList()
{cout << "In LinkList Destructor..."
    << endl;
    ListNode* current = head;
    ListNode * previous = nullptr;
    while(current != nullptr)
    { previous = current;
        current = current->getNext();
        delete previous;
    } // end while loop
} // end of destructor

void LinkList::insert(Book value) // adds in order by integer value
{ListNode * current = head;
    ListNode * previous = nullptr;
    if (current == nullptr) // create a newNode
    { ListNode *newNode = new ListNode;
        newNode->setValue(value);
        newNode->setNext(nullptr);
        head=newNode; }
    else
    {// iterate until we get to the end of the list
        // or find where to insert in order (low to high by integer value)
        while(current->getNext() != nullptr &&
              current->getValue().getArea() >= value.getArea())
        {   if (current->getValue().getArea() == value.getArea()) {
                if (current->getValue().getPages() > value.getPages()) {
                    previous = current;
                    current = current->getNext();
                } else {
                    break;
                }
            } else {
                previous= current;
                current = current->getNext();
            }
        }
        // now create a new ListNode
        if (current == head)
        { // insert at front
            ListNode *newNode = new ListNode;
            newNode->setValue(value);
            newNode->setNext(current);
            head = newNode;
        }
        else
        {
            if (current->getNext() == nullptr) {
                if (current->getValue().getArea() == value.getArea()) {
                    if (current->getValue().getPages() > value.getPages()) {
                        //insertion less pages, insert to right
                        previous= current;
                        ListNode *newNode = new ListNode;
                        newNode->setValue(value);
                        newNode->setNext(nullptr);
                        current->setNext(newNode);
                    } else {
                        //insertion more pages, insert to left
                        ListNode *newNode = new ListNode;
                        newNode->setValue(value);
                        newNode->setNext(current);
                        previous->setNext(newNode);
                    }
                } else {
                    if (current->getValue().getArea() > value.getArea()) {
                        //insertion is smaller area, place to right
                        previous= current;
                        ListNode *newNode = new ListNode;
                        newNode->setValue(value);
                        newNode->setNext(nullptr);
                        current->setNext(newNode);
                    } else {
                        //insertion is bigger area, place to left
                        ListNode *newNode = new ListNode;
                        newNode->setValue(value);
                        newNode->setNext(current);
                        previous->setNext(newNode);
                    }
                }
            } else
            { ListNode * newNode = new ListNode;
                newNode->setValue(value);
                newNode->setNext(current);
                previous->setNext(newNode);}
        }
    }
} // end of insert

void LinkList::insertLoaner(Book value) // adds in order by integer value
{ListNode * current = head;
    ListNode * previous = nullptr;
    if (current == nullptr) // create a newNode
    { ListNode *newNode = new ListNode;
        newNode->setValue(value);
        newNode->setNext(nullptr);
        head=newNode; }
    else
    {// iterate until we get to the end of the list
        // or find where to insert in order (low to high by integer value)
        while(current->getNext() != nullptr &&
              current->getValue().getReturnDate() < value.getReturnDate())
        {   previous = current;
            current = current->getNext();
        }
        // now create a new ListNode
        if (current == head)
        { // insert at front
            {if (current->getValue().getReturnDate() < value.getReturnDate()) {
                //insertion less pages, insert to right
                previous= current;
                ListNode *newNode = new ListNode;
                newNode->setValue(value);
                newNode->setNext(nullptr);
                current->setNext(newNode);
            } else {
                
                //insertion is bigger area, place to left
                ListNode *newNode = new ListNode;
                newNode->setValue(value);
                newNode->setNext(current);
                previous->setNext(newNode);
                
            }
                
            }
        }
        else
        {if (current->getValue().getReturnDate() > value.getReturnDate()) {
                //insertion less pages, insert to right
                previous= current;
                ListNode *newNode = new ListNode;
                newNode->setValue(value);
                newNode->setNext(nullptr);
                current->setNext(newNode);
            } else {
                
                    //insertion is bigger area, place to left
                    ListNode *newNode = new ListNode;
                    newNode->setValue(value);
                    newNode->setNext(current);
                    previous->setNext(newNode);
                
            }
            
        }
    }
} // end of insert

Book& LinkList::find(string title) {
    ListNode * current = head;
    ListNode * previous = nullptr;
        while (current->getValue().getTitle() != title) {
            if (current->getNext() != nullptr) {
                previous= current;
                current = current->getNext();
            }
    }
    
    return (current->getValue());
} // end of find

bool LinkList::exceptional(string title) {
    ListNode * current = head;
    ListNode * previous = nullptr;
    while (current->getNext() != nullptr &&
           current->getValue().getTitle() != title) {
        previous= current;
        current = current->getNext();
    }
    if (current->getNext() == nullptr) {
        if (current->getValue().getTitle() == title) {
            if (current->getValue().loanStatus()) {
                cout << title << " ALREADY LOANED OUT." << endl;
                return false;
            } else {
                return true;
            }
        } else {
            cout << title << " NOT IN LIBRARY." << endl;
            return false;
        }
    }
    if (current->getValue().getTitle() == title) {
        if (current->getValue().loanStatus()) {
            cout << title << " ALREADY LOANED OUT." << endl;
            return false;
        } else {
            return true;
        }
    }
    current->getValue().loanedOut();
    return true;
}

int LinkList::count() {
    int totalBooks = 0;
    ListNode * current = head;
    ListNode * previous = nullptr;
    while (current->getNext() != nullptr) {
        totalBooks++;
        previous= current;
        current = current->getNext();
    }
    totalBooks++;
    return totalBooks;
}

int LinkList::countShelf() {
    int totalBooks = 0;
    ListNode * current = head;
    ListNode * previous = nullptr;
    while (current->getNext() != nullptr) {
        if (current->getValue().loanStatus() == false) {
            totalBooks++;
        }
        previous= current;
        current = current->getNext();
    }
    if (current->getValue().loanStatus() == false) {
        totalBooks++;
    }
    return totalBooks;
}

Book LinkList::getBook(int idx) {
    ListNode * current = head;
    ListNode * previous = nullptr;
    int loc = 0;
    while (current->getNext() != nullptr) {
        if (idx == loc) {
            return current->getValue();
        } else {
            previous= current;
            current = current->getNext();
            loc++;
        }
    }
    return current->getValue();
}
