#include "User.hpp"


    User::User(string n, string pass){
        userID = counterUser++;
        name = n;
        password = pass;
    }


    User::User(string n, string pass , int id){
        userID = id;
        name = n;
        password = pass;
    }


    User::User() {
        
        //userID = counterUser++;

    }

    User::~User() {}

    void User::setName(string userName) {
        name = userName;
    }

    string User::getName() {
        return name;
    }

    void User::setPassword(string userPassword) {
        password = userPassword;
    }

    string User::getPassword() {
        return password;
    }

    int User::getUserID() {
        return userID;
    }


     int  User::getCounterUser(){
        return counterUser;
    }
     void User::setCounterUser(int count){
        counterUser = count;
    }


    
    
bool User::operator==(const User& other) const {
    return (name == other.name && userID == other.userID && password == other.password);
}




void User::setdisplayed(){
    displayed = true;
}
int User::counterUser = 0; // Initialize static member variable



/*
#include "User.hpp"
#include <iostream>

int main() {
    // Test User class

    // Create users
    User user1("Alice", "password1");
    User user2("Bob", "password2");

    // Display user information
    std::cout << "User 1 ID: " << user1.getUserID() << std::endl;
    std::cout << "User 1 Name: " << user1.getName() << std::endl;
    std::cout << "User 1 Password: " << user1.getPassword() << std::endl;

    std::cout << "User 2 ID: " << user2.getUserID() << std::endl;
    std::cout << "User 2 Name: " << user2.getName() << std::endl;
    std::cout << "User 2 Password: " << user2.getPassword() << std::endl;

    // Update user information
    user1.setName("AliceUpdated");
    user1.setPassword("newpassword1");

    // Display updated user information
    std::cout << "Updated User 1 Name: " << user1.getName() << std::endl;
    std::cout << "Updated User 1 Password: " << user1.getPassword() << std::endl;

    // Display counter
    std::cout << "Counter User: " << User::getCounterUser() << std::endl;

    return 0;
}

*/

