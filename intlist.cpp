// intlist.cpp
// Implements class IntList
// ANDREW XIONG, 7 JANUARY 2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
/* FIX */
IntList::IntList(const IntList& source) {
    head = nullptr;
    tail = nullptr;
    Node* curr = source.head;
    while(curr){
        push_back(curr->info);
        curr = curr->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* curr = head;
    Node* temp = nullptr;
    while(curr){
        temp = curr->next;
        delete curr;
        curr = temp;
    }
	head = nullptr;
	tail = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    Node* curr = head;
    int s = 0;
    while(curr){
        s += curr->info;
        curr = curr->next;
    }
    return s;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = head;
    while(curr){
        if(curr->info == value)
            return true;
        curr = curr->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node* curr = head;
    int max = -2147483648;
    while(curr){
        if(curr->info > max)
            max = curr->info;
        curr = curr->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    Node* curr = head;
    double avg = sum();
    int co = count();
    return (avg / co);
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* n = new Node;
    n->info = value;
    n->next = head;
    head = n;
    if(!tail)
        tail = n;
}

// append value at end of list
void IntList::push_back(int value) {
    Node* n = new Node;
    n->info = value;
    n->next = nullptr;
    if(!head)
        head = n;
    if(tail)
        tail->next = n;
    tail = n;
}

// return count of values
int IntList::count() const {
    Node* curr = head;
    int c = 0;
    while(curr){
        c++;
        curr = curr->next;
    }
    return c;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    Node* curr = head;
    Node* temp = nullptr;
    while(curr){
        temp = curr->next;
        delete curr;
        curr = temp;
    }
	head = nullptr;
	tail = nullptr;

    curr = source.head;
    while(curr){
        push_back(curr->info);
        curr = curr->next;
    }

    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

