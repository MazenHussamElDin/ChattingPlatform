#include "mainpage.h"
#include <QApplication>
#include <QIcon>
#include "SystemManager.hpp"

void excafter() {
    cout << "yes";
    SystemManager::getInstance().writeToFileUser();
    SystemManager::getInstance().writeToFileChat();
    SystemManager::getInstance().writeToFileMessages();
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Load the icon file
    QIcon appIcon("G:/Semester 5/Data Structures/Project/untitledehab/icon.jpg"); // Replace with your icon file path
    SystemManager::getInstance().readFromFileUser();
    SystemManager::getInstance().readFromFileChat();
    SystemManager::getInstance().readFromFileMessages();

    // Set the application icon
    a.setWindowIcon(appIcon);

    MainPage w;
    w.show();

    // Call excafter before returning
    excafter();

    return a.exec();
}


