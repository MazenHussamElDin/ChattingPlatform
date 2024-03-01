
#include <iostream>

#include "Message.hpp"
#include "User.hpp"

using namespace std;

template<typename listdata>
class LinkedList {
public:
    class Node {
    public:

        listdata data;
        Node* next; 

        Node() : next(0) {}
        Node(listdata dataValue) : data(dataValue), next(0) {}
    };

    
    Node* first;
    int mySize;

public:
    typedef Node* NodePointer;
    LinkedList(); 
    LinkedList(const LinkedList& origList); 
    const LinkedList<listdata>& operator=(const LinkedList<listdata>& rightSide); 
    ~LinkedList();
    bool empty();
    void insert(listdata &dataVal); 
    void erase(int index);
    int search(listdata dataVal);
    void display() const; 
    Node* getFirst();

};


