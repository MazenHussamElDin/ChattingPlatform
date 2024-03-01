#include "Message.hpp"
#include <ctime>

Message::Message() : senderID(0) {
    time_t now;
    struct tm nowLocal;
    now = time(NULL);
    nowLocal = *localtime(&now);
    char timeString[6]; // 5 characters for HH:MM + 1 for the null terminator
    strftime(timeString, sizeof(timeString), "%H:%M", &nowLocal);
    timestamp = timeString;

}



// Parameterized constructor
Message::Message(string text, int sender) : content(text), senderID(sender) {
    time_t now;
    struct tm nowLocal;
    now = time(NULL);
    nowLocal = *localtime(&now);
    char timeString[6]; // 5 characters for HH:MM + 1 for the null terminator
    strftime(timeString, sizeof(timeString), "%H:%M", &nowLocal);
    timestamp = timeString;
}
//overloaded const for read function
Message::Message(string text, int sender, string timeStamp) : content(text), senderID(sender), timestamp(timeStamp) {


}

// Setter for content
void Message::setContent(string text) {
    content = text;
}

// Getter for content
string Message::getContent() {
    return content;
}

// Getter for senderID
int Message::getSenderID() {
    return senderID;
}

string Message :: getTimeStamp(){
    return timestamp;
}


bool Message::operator==(const Message& other) const {
    return (content == other.content && senderID == other.senderID && timestamp == other.timestamp);
}
