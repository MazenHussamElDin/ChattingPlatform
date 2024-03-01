

#include <iostream>
#include <cstring>

#include"Chat.hpp"

using namespace std;

template <typename Tvalue>
class Hmap {
public:
    const static int TableSize = 11;

    class Node {
    public:
        int key;
        Node* next;
        Tvalue value;
        Node();
        Node(int key, Tvalue value);
    };

    int mySize;
    Node* table[TableSize];

    int hash(const int& key);

public:
    Hmap();
    ~Hmap();
    int getMySize();
    Hmap(const Hmap& other);
    Hmap& operator=(const Hmap& other);
    void insert(const int& key, const Tvalue& value);
    void erase(const int& key);
    Tvalue search(const int key, bool& found);
    Tvalue* search(bool& found , const int key);
    void display();
    bool isEmpty();
};

