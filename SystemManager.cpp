#include "SystemManager.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

void SystemManager::createChat(LinkedList<User>list){
    
    Chat newChat(list);
    chatmap.insert(newChat.getChatID() , newChat); 
    cout << "CREATE CHAT INVOKED"<< endl;
        
}


void SystemManager::createChat(LinkedList<User>list, int& id){

    Chat newChat(list);
    chatmap.insert(newChat.getChatID() , newChat);
    cout << "CREATE CHAT INVOKED"<< endl;
    id = newChat.getChatID();

}


 /*void SystemManager::sendMessage(int chatID, string content, int senderID){

    bool found;
    Chat chat = chatmap.search(chatID, found);
    cout << "SEND MESSAGE INVOKED"<< endl;
    if(found){
        Message m(content, senderID);
        chat.setMessage(m);
    }else{
        cerr << "CHAT NOT FOUND!";
    }
}*/

void SystemManager::sendMessage(int chatID, Message msg){

    int index = chatmap.hash(chatID);
    Hmap<Chat>::Node* currentNode = chatmap.table[index];

    while (currentNode != nullptr) {
        if (currentNode->key == chatID) {
            // Access the target Chat and modify properties
            currentNode->value.chatMessages.insert(msg);
            break;
        }
        currentNode = currentNode->next;
    }

}


void SystemManager::setuser1(User &user1){
    currentuser1 = user1;

}

User& SystemManager::getuser1(){
    return currentuser1;
}

void SystemManager::setuser2(User &user2){
    currentuser2 = user2;
}

User& SystemManager::getuser2(){
    return currentuser2;
}

 void SystemManager::addUser(string name, string password){
    User user1(name, password);
    usermap.insert(user1.getUserID(),user1);
    cout << user1;

}


 void SystemManager::writeToFileUser() {
    ofstream outfile;
    outfile.open("G:/Semester 5/Data Structures/Project/untitledehab/userdata.txt");
    Hmap<User>::Node* ptr;

    for (int i = 0; i < usermap.TableSize; i++) {
        ptr = usermap.table[i];
        while (ptr != nullptr) {
            outfile << ptr->value.getName() << ":" << ptr->value.getUserID() << ":" << ptr->value.getPassword() << endl;
            ptr = ptr->next;
        }
    }

    outfile.close();
}


 void SystemManager::readFromFileUser() {
    ifstream infile("G:/Semester 5/Data Structures/Project/untitledehab/userdata.txt");
    if (!infile.is_open()) {
        // Handle error: Unable to open the file
        cerr << "Error: Unable to open the file 'userdata.txt'" << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string name, userID, password;

        getline(ss, name, ':');
        getline(ss, userID, ':');
        getline(ss, password, ':');

        // Assuming User class has a constructor that takes name, userID, and password
        User user(name,  password);
        cout << user;
        // Add the user to the hash map
        usermap.insert(user.getUserID(), user);
    }

    infile.close();
}

 bool SystemManager:: login(const string& username, const string& password, User& u1) {
    for (int i = 0; i < usermap.TableSize; ++i) {
        Hmap<User>::Node* currentNode = usermap.table[i];

        while (currentNode != nullptr) {

            if (currentNode->value.getName() == username && currentNode->value.getPassword() == password) {
                u1 = currentNode->value;
                return true;
            }

            currentNode = currentNode->next;
        }
    }

    return false;
}



SystemManager& SystemManager::getInstance() {
    static SystemManager instance;
    return instance;
}





// -------- chat files ----------

void SystemManager::readFromFileChat() {
    ifstream infile("G:/Semester 5/Data Structures/Project/untitledehab/chatdata.txt");
    bool found = false;

    if (!infile.is_open()) {
        cerr << "Error: Unable to open the file 'chatdata.txt'" << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        LinkedList<User> tempList;
        stringstream ss(line);
        string chatID, userID;

        getline(ss, chatID, ':');

        try {
            int chatid = stoi(chatID);


            while (getline(ss, userID, '%')) {
                try {
                    int userid = stoi(userID);
                    User* u1p = usermap.search(found, userid);
                    cout<< "UserId " << userid << userID<< endl;
                    if (found) {
                        string name = u1p->getName();
                        string pass = u1p->getPassword();
                        int id = u1p->getUserID();
                        User u1(name , pass, id);
                        cout << u1 << endl;
                        tempList.insert(u1);
                    }
                    found = false;
                } catch (const invalid_argument& e) {
                    cerr << "Invalid argument: " << e.what() << endl;
                }
            }

            createChat(tempList);
            cout << "A chat has been created" << endl;

        } catch (const invalid_argument& e) {
            cerr << "Invalid argument: " << e.what() << endl;
            // Handle the invalid argument error as needed
        }
    }

    infile.close();
}


void SystemManager::writeToFileChat() {
    ofstream outfile;
    outfile.open("G:/Semester 5/Data Structures/Project/untitledehab/chatdata.txt");
    Hmap<Chat>::Node* ptr;
    LinkedList<User> :: Node* lptr ;

    cout << endl << "--Write(chat) invoked--\n";
    for (int i = 0; i < chatmap.mySize; i++) {
        ptr = chatmap.table[i];
        while (ptr != nullptr) {
            lptr = ptr->value.users.first;
            if (lptr == nullptr){cout << "null";}

            outfile << ptr->value.getChatID() << ":";

            while (lptr != nullptr){
                outfile << lptr->data.getUserID() << "%";
                lptr = lptr ->next;

            }
            ptr = ptr->next;
        }
        outfile << endl;
    }

    outfile.close();
}


void SystemManager::readFromFileMessages() {
    try {
        std::ifstream infile("G:/Semester 5/Data Structures/Project/untitledehab/messagedata.txt");
        if (!infile.is_open()) {
            throw std::runtime_error("Error: Unable to open the file 'messagedata.txt'");
        }

        std::string line;
        while (getline(infile, line)) {
            std::istringstream iss(line);
            std::string chatID;
            bool found = false;

            getline(iss, chatID, '+');
            int chatid = stoi(chatID);

            Chat* chatptr;
            chatptr = chatmap.search(found, chatid);
            std::string messageData;

            while (getline(iss, messageData, '|')) {
                std::string content = messageData;
                getline(iss, messageData, '|');
                std::string senderID = messageData;
                int senderidd = stoi(senderID);
                getline(iss, messageData, '~');
                std::string timestamp = messageData;
                Message mg1(content, senderidd,
                            timestamp);
                chatptr->chatMessages.insert(mg1);
            }
        }

        infile.close();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}




void SystemManager::writeToFileMessages() {
    try {
        std::ofstream outfile("G:/Semester 5/Data Structures/Project/untitledehab/messagedata.txt");
        if (!outfile.is_open()) {
            throw std::runtime_error("Error: Unable to open the file 'message.txt'");
        }

        for (int i = 0; i < chatmap.TableSize; ++i) {
            Hmap<Chat>::Node* currentNode = chatmap.table[i];

            while (currentNode != nullptr) {
                outfile << currentNode->value.getChatID() << "+";

                LinkedList<Message>::NodePointer messagePtr = currentNode->value.chatMessages.getFirst();

                while (messagePtr != nullptr) {
                    outfile << messagePtr->data.getContent() << "|";
                    outfile << messagePtr->data.getSenderID() << "|";
                    outfile << messagePtr->data.getTimeStamp() << "~";
                    messagePtr = messagePtr->next;
                }

                outfile << "\n";
                currentNode = currentNode->next;
            }
        }

        outfile.close();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}





Hmap<Chat> SystemManager::DisplayUserChats1(int currentUserid) {
    Hmap<Chat> currentChat1;  // Create a local hashmap for this function

    Hmap<Chat>::Node* mapPtr;
    LinkedList<User>::Node* lPtr;

    for (int i = 0; i < chatmap.mySize; i++) {
        mapPtr = chatmap.table[i];
        while (mapPtr != nullptr) {
            lPtr = mapPtr->value.users.first;
            while (lPtr != nullptr) {
                if (lPtr->data.getUserID() == currentUserid) {
                    cout << mapPtr->value.getChatID();
                    currentChat1.insert(mapPtr->value.getChatID(), mapPtr->value);
                    break;
                }
                lPtr = lPtr->next;
            }
            mapPtr = mapPtr->next;
        }
    }

    return currentChat1;
}
Hmap<Chat> SystemManager::DisplayUserChats2(int currentUserid) {
    Hmap<Chat> currentChat2;  // Create a local hashmap for this function

    Hmap<Chat>::Node* mapPtr;
    LinkedList<User>::Node* lPtr;

    for (int i = 0; i < chatmap.mySize; i++) {
        mapPtr = chatmap.table[i];
        while (mapPtr != nullptr) {
            lPtr = mapPtr->value.users.first;
            while (lPtr != nullptr) {
                if (lPtr->data.getUserID() == currentUserid) {
                    cout << mapPtr->value.getChatID();
                    currentChat2.insert(mapPtr->value.getChatID(), mapPtr->value);
                    break;
                }
                lPtr = lPtr->next;
            }
            mapPtr = mapPtr->next;
        }
    }

    return currentChat2;
}









