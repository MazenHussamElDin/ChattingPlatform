#include "Chat.hpp"



Chat::Chat()  {
    //chatID = counterChat++;
}

Chat::Chat(int i)  {
    chatID = -1;
}

Chat::~Chat() //edit it
{

}




Chat::Chat(LinkedList<User> list) : users(list) {
    chatID = counterChat++;
}

int Chat::getChatID() const {
    return chatID;
}

void Chat::setUsers(LinkedList<User> alist) {
    users = alist;
}

LinkedList<User> Chat::getUsers() const {
    return users;
}

void Chat::setMessage(Message message) {
    chatMessages.insert(message);
}

LinkedList<Message> Chat::getMessage() const {
    return chatMessages;
}

int Chat::getCounterChat(){
    return counterChat;
}

void Chat::setCounterChat(int count){
    counterChat = count;
}



int Chat::counterChat = 0;

