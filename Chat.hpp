#include <iostream>
#include <cstring>
#include <string>
#include "LinkedList.hpp"
using namespace std;

class Chat
{
private:
    int chatID;

    static int counterChat;
public:
    LinkedList<User> users;
    LinkedList<Message> chatMessages;
    Chat();
    Chat(int i);
    Chat(LinkedList<User> list);
    ~Chat();
    int getChatID() const;
    void setUsers(LinkedList<User> alist);
    LinkedList<User> getUsers() const;
    void setMessage(Message message);
    LinkedList<Message> getMessage() const;
    int getCounterChat();
    void setCounterChat(int count);
    friend std::ostream& operator<<(std::ostream& os, const Chat& c) {
        os << "chat ID: " << c.chatID ;
        return os;
    }

};
