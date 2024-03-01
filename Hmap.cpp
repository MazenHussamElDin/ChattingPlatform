#include "Hmap.hpp"



template <typename Tvalue>
Hmap<Tvalue>::Node::Node() : key(0), value(Tvalue()), next(nullptr) {}

template <typename Tvalue>
Hmap<Tvalue>::Node::Node(int key, Tvalue value) : key(key), value(value), next(nullptr) {}

template <typename Tvalue>
Hmap<Tvalue>::Hmap() : mySize(0) {
    for (int i = 0; i < TableSize; i++)
        table[i] = nullptr;
}


template <typename Tvalue>
Hmap<Tvalue>::~Hmap() {
    for (int i = 0; i < TableSize; ++i) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        table[i] = nullptr;
    }
}

// copy constructor
template <typename Tvalue>
Hmap<Tvalue>::Hmap(const Hmap& other) {
        mySize = other.mySize;
        for (int i = 0; i < TableSize; i++) {
            if (other.table[i]) {
                table[i] = new Node(other.table[i]->key, other.table[i]->value);
                Node* current = other.table[i]->next;
                Node* currentCopy = table[i];
                while (current) {
                    currentCopy->next = new Node(current->key, current->value);
                    current = current->next;
                    currentCopy = currentCopy->next;
                }
            } else {
                table[i] = nullptr;
            }
        }
    }


// Operator overloading
template <typename Tvalue>
Hmap<Tvalue>& Hmap<Tvalue>:: operator=(const Hmap& other) {
        if (this != &other) { // Check for self-assignment
            // Clear the existing data in this instance
            for (int i = 0; i < TableSize; ++i) {
                Node* current = table[i];
                while (current != nullptr) {
                    Node* next = current->next;
                    delete current;
                    current = next;
                }
                table[i] = nullptr;
            }
            mySize = 0;

            // Copy the data from 'other' to this instance
            for (int i = 0; i < TableSize; ++i) {
                Node* currentOther = other.table[i];
                while (currentOther != nullptr) {
                    insert(currentOther->key, currentOther->value);
                    currentOther = currentOther->next;
                }
            }
        }
        return *this;
    }    

template <typename Tvalue>
void Hmap<Tvalue>::insert(const int& key, const Tvalue& value) {
    int index = hash(key);
    if (table[index] == nullptr) {
        table[index] = new Node(key, value);
        mySize++;
    } else {
        Node* ptr = table[index];
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = new Node(key, value);
        mySize++;
    }
}


//overload to return pointer (send bool first)
template <typename Tvalue>
Tvalue* Hmap<Tvalue>::search(bool& found , const int key) {
    int index = hash(key);
    Node* ptr = table[index];

    while (ptr != nullptr) {
        if (ptr->key == key) {
            found = true;
            return &(ptr->value);
        }
        ptr = ptr->next;
    }

    found = false;
    return nullptr;
}


template <typename Tvalue>
int Hmap<Tvalue>::getMySize() {
    return mySize;
}

template <typename Tvalue>
int Hmap<Tvalue>::hash(const int& key) {
    return key % TableSize;
}

template <typename Tvalue>
void Hmap<Tvalue>::erase(const int& key) {
    int index = hash(key);
    if (table[index] == nullptr) {
        std::cerr << "INDEX ALREADY DOESN'T EXIST";
    } else if (table[index]->key == key) {
        Node* temp = table[index];
        table[index] = table[index]->next;
        delete temp;
        mySize--;
    } else {
        Node* current = table[index]->next;
        Node* prev = table[index];

        while (current != nullptr && current->key != key) {
            prev = current;
            current = current->next;
        }

        if (current != nullptr) {
            prev->next = current->next;
            delete current;
            mySize--;
        }
    }
}

template <typename Tvalue>
Tvalue Hmap<Tvalue>::search(const int key, bool& found) {
    Tvalue val;
    int index = hash(key);
    Node* ptr = table[index];

    while (ptr != nullptr) {
        if (ptr->key == key) {
            found = true;
            val = ptr->value;
            return val;
        }
        ptr = ptr->next;
    }

    found = false;
    return val;
}

template <typename Tvalue>
void Hmap<Tvalue>::display() {
    if (isEmpty())
        std::cerr << "EMPTY TABLE";
    else {
        for (int i = 0; i < TableSize; i++) {
            Node* ptr = table[i];
            while (ptr != nullptr) {
                std::cout << ptr->value << std::endl;
                ptr = ptr->next;
            }
        }
    }
}

template <typename Tvalue>
bool Hmap<Tvalue>::isEmpty() {
    return (mySize == 0);
}


template class Hmap<Chat>;
template class Hmap<User>;


/*
using namespace std;
#include <iostream>
class person
{

string name;
public:
int number;
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
    Hmap<person> myList;

    person p1(1, "mazen");
    person p2(2, "yomna");
    person p3(3, "badr");
    person p4(4, "menna");
    myList.insert(p1.number,p1);
    myList.insert(p2.number,p2);
    myList.insert(p3.number,p3);
    myList.insert(p4.number,p4);
    myList.display();
}
*/



/*
int main() {
    Hmap<std::string> myMap;

    myMap.insert(1, "One");
    myMap.insert(2, "Two");
    myMap.insert(3, "Three");
    myMap.insert(13, "Thirteen");

    myMap.display();

    bool found = false;
    std::string value = myMap.search(2, found);
    if (found) {
        std::cout << "Found: " << value << std::endl;
    } else {
        std::cout << "Not found!" << std::endl;
    }

    myMap.erase(2);
    myMap.display();

    return 0;
}

*/


