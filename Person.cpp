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
