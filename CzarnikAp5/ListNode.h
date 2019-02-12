#ifndef ListNode_h
#define ListNode_h

#include <iostream>
#include "Book.h"

using namespace std;

class ListNode {  // same as before
    public:
        ListNode()
        {  next = nullptr; }
        ~ListNode(){
                cout  << "In  ListNode Destructor... Value: " <<
            value.getTitle() << endl;
        }
    Book& getValue(){ return value; }
    void setValue(Book val){ value = val; }
    ListNode* getNext(){ return next; }
    void setNext(ListNode * nxt){ next = nxt; }
    private:
    Book value;
    ListNode * next;
    
};

#endif
