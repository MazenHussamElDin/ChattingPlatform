#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>


#include "Hmap.hpp"


class SystemManager{

  public:

   Hmap<Chat> chatmap;
   Hmap<User> usermap;
   Hmap<Chat> currentChat1;
   Hmap<Chat> currentChat2;

   User currentuser1;
   User currentuser2;
   void createChat(LinkedList<User>list);
   void createChat(LinkedList<User>list, int& id);

   //void sendMessage(int chatID, string content, int senderID);
   void sendMessage(int chatID, Message msg);

   void addUser(string name, string password);
   void writeToFileUser();
   void readFromFileUser();

   void writeToFileChat();
   void readFromFileChat();

   void writeToFileMessages();
   void readFromFileMessages();

   bool login(const string& username, const string& password, User& u1);

   void setuser1(User& user1);
   void setuser2(User& user2);
   User& getuser1();
   User& getuser2();
   //LinkedList<Chat> DisplayUserChats(int currentuserid);
   Hmap<Chat> DisplayUserChats1(int currentUserid);
   Hmap<Chat> DisplayUserChats2(int currentUserid);
   static SystemManager& getInstance();
 };
