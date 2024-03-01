#include "LinkedList.hpp"

#include <string>
using namespace std;

// constructor
template<typename listdata>
LinkedList<listdata>::LinkedList() : first(nullptr), mySize(0) {}

template<typename listdata>
LinkedList<listdata>::LinkedList(const LinkedList<listdata>& origList) : first(0), mySize(origList.mySize) {
    if (mySize == 0) return;
    LinkedList::NodePointer origPtr, lastPtr;
    first = new Node(origList.first->data);  
    lastPtr = first;
    origPtr = origList.first->next;
    while (origPtr != 0)
    {
        lastPtr->next = new Node(origPtr->data);
        origPtr = origPtr->next;
        lastPtr = lastPtr->next;
    }
}

template<typename listdata>
typename LinkedList<listdata>::Node* LinkedList<listdata>::getFirst(){
    return first;
}


//destructor
template<typename listdata>
inline LinkedList<listdata>::~LinkedList() {
    LinkedList::NodePointer prev = first, ptr;
    while (prev != nullptr)
    {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
}


template<typename listdata>
const LinkedList<listdata>& LinkedList<listdata>::operator=(const LinkedList<listdata>& rightSide) {
    mySize = rightSide.mySize;

    if (mySize == 0) {
        first = 0;
        return *this;
    }
    if (this != &rightSide)
    {
        this->~LinkedList();
        LinkedList::NodePointer origPtr, lastPtr;
        first = new Node(rightSide.first->data);  
        lastPtr = first;
        origPtr = rightSide.first->next;

        while (origPtr != 0)
        {
            lastPtr->next = new Node(origPtr->data);
            origPtr = origPtr->next;
            lastPtr = lastPtr->next;
        }
    }
    return *this;
}



template<typename listdata>
bool LinkedList<listdata>::empty() {
    return mySize == 0;
}



template<typename listdata>
void LinkedList<listdata>::insert(listdata& dataVal) {
    mySize++;
    LinkedList<listdata>::NodePointer newPtr = new Node(dataVal);

    if (first == nullptr) {
        first = newPtr;
    } else {
        LinkedList<listdata>::NodePointer ptr = first;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = newPtr;
    }
}


template<typename listdata>
void LinkedList<listdata>::erase(int index) {
    if (index < 0 || index >= mySize) {
        cerr << "Illegal location to delete -- " << index << endl;
        return;
    }

    mySize--;
    LinkedList<listdata>::NodePointer ptr = first;
    if (index == 0) {
        first = ptr->next;
        delete ptr;
    } else {
        for (int i = 0; i < index - 1; ++i) {
            ptr = ptr->next;
        }
        LinkedList<listdata>::NodePointer temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
    }
}

template<typename listdata>
int LinkedList<listdata>::search(listdata dataVal) {
    int loc;
    LinkedList::NodePointer tempP = first;
    for (loc = 0; loc < mySize; loc++)
        if (tempP->data == dataVal)
            return loc;
        else
            tempP = tempP->next;
    return -1;
}

template<typename listdata>
void LinkedList<listdata>::display() const {
    LinkedList::NodePointer ptr = first;
    while (ptr != 0)
    {
        cout << ptr->data << "  ";
        ptr = ptr->next;
    }
}


template class LinkedList<Message>;
template class LinkedList<User>;


/*
using namespace std;
#include <iostream>
class person
{
int number;
string name;
public:
person(int num, string n){
    number = num;
    name = n;
}

friend std::ostream& operator<<(std::ostream& os, const person& p) {
        os << p.number << " " << p.name;
        return os;
    }

};


int main(){
    LinkedList<person> myList;

    person p1(1, "mazen");
    person p2(2, "yomna");
    person p3(3, "badr");
    person p4(4, "menna");
    myList.insert(p1);
    myList.insert(p2);
    myList.insert(p3);
    myList.insert(p4);
    myList.display();
}

*/





/*
int main() {
    // Create an integer linked list
    LinkedList<int> myList;

    // Insert elements into the list
    for (int i = 1; i <= 5; ++i) {
        myList.insert(i);
    }

    // Display the list
    cout << "List after insertions: ";
    myList.display();
    cout << endl;

    // Search for an element
    int searchVal = 3;
    int searchResult = myList.search(searchVal);
    if (searchResult != -1) {
        cout << "Found value " << searchVal << " at index " << searchResult << endl;
    } else {
        cout << "Value " << searchVal << " not found in the list" << endl;
    }

    // Erase an element
    int eraseIndex = 2;
    myList.erase(eraseIndex);

    // Display the list after erasing
    cout << "List after erasing element at index " << eraseIndex << ": ";
    myList.display();
    cout << endl;

    return 0;
}

*/
