#include "createchatpage.h"
#include "ui_createchatpage.h"
#include "SystemManager.hpp"
#include "newuserpage.h"
#include <QCheckBox>
CreateChatPage::CreateChatPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateChatPage)
{
    ui->setupUi(this);

}

CreateChatPage::~CreateChatPage()
{
    delete ui;
}

void CreateChatPage::funcCreatechatpage1(int id){

    cout << "funccreatechatpage1 begin" << endl;
    cout << "sent id "<<id << endl;
    id1 = id;
    cout << "received id "<<id1 << endl;
    if(id == 1){
    //Hmap<User> users = SystemManager::getInstance().usermap;
    for(int i=0; i<11; i++){
        Hmap<User>:: Node* ptr = SystemManager::getInstance().usermap.table[i];
        while(ptr!=nullptr){
            if(ptr->value.getUserID() != SystemManager::getInstance().getuser1().getUserID()){
                cout << ptr->value.getName();
                QCheckBox *checkBox = new QCheckBox(QString::fromStdString(ptr->value.getName()));
                checkBox->setObjectName(QString::number(ptr->value.getUserID()));
                ui->UsersLayout->addWidget(checkBox);
            }
            ptr = ptr->next;
        }
    }
    }else if(id ==2){
        //Hmap<User> users = SystemManager::getInstance().usermap;
        for(int i=0; i<11; i++){
            Hmap<User>:: Node* ptr = SystemManager::getInstance().usermap.table[i];
            while(ptr!=nullptr){
                if(ptr->value.getUserID() != SystemManager::getInstance().getuser2().getUserID()){
                    cout << ptr->value.getName();
                    QCheckBox *checkBox = new QCheckBox(QString::fromStdString(ptr->value.getName()));
                    checkBox->setObjectName(QString::number(ptr->value.getUserID()));
                    ui->UsersLayout->addWidget(checkBox);
                }
                ptr = ptr->next;
            }

        }
    }
     cout << "funccreatechatpage1 end" << endl;
}

void CreateChatPage::on_CreateBtn_clicked()
{
     cout << "createbtn begin" << endl;
    cout << "--------------id1------- " << id1 <<endl;
    LinkedList<User> selectedusersList;
     if(id1==1){
        selectedusersList.insert(SystemManager::getInstance().getuser1());
     }else if(id1 ==2){
         selectedusersList.insert(SystemManager::getInstance().getuser2());
     }

    bool found;
    for (int i = 0; i < ui->UsersLayout->count(); ++i) {
        QWidget *widget = ui->UsersLayout->itemAt(i)->widget();
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(widget);

        if (checkBox && checkBox->isChecked()) {
            QString objectName = checkBox->objectName();
            cout << objectName.toStdString();
            selectedusersList.insert(*SystemManager::getInstance().usermap.search( found, objectName.toInt()));
            qDebug() << "Selected checkbox object name:" << objectName;
        }
    }


    cout << "Linked list selecteddddddd" << endl;
    LinkedList<User>::Node* listptr = selectedusersList.first;
    while (listptr!=nullptr){
        cout << listptr->data << endl;
        listptr = listptr->next;
    }

    cout << "Before" << endl;
    for(int i=0; i<11; i++){
        Hmap<Chat>:: Node* ptr =  SystemManager::getInstance().chatmap.table[i];
        while(ptr!=nullptr){

            cout << ptr->value;
            ptr = ptr->next;
        }
    }

    int id;
    SystemManager::getInstance().createChat(selectedusersList, id);
    emit successfullyadded(id);


    cout << "After: " <<endl;
    for(int i=0; i<11; i++){
        Hmap<Chat>:: Node* ptr =  SystemManager::getInstance().chatmap.table[i];
        while(ptr!=nullptr){

            cout << ptr->value;
            //cout << ptr->value.getUsers().first->data;
            ptr = ptr->next;
        }
    }

     cout << "create btn" << endl;
    hide();
}

