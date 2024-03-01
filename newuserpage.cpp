#include "newuserpage.h"
#include "ui_newuserpage.h"
#include "SystemManager.hpp"
#include "addaccountpage.h"
#include "createchatpage.h"


NewUserPage::NewUserPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewUserPage)
{
    ui->setupUi(this);
    mainlayout =  new QVBoxLayout(NewUserPage :: ui -> AllMessagesW);//
    ui->widgett->hide();
    ui->scrollArea->hide();
    ui->AllMessagesW->hide();
    ui->sendMessageW->hide();
    createP= new CreateChatPage();
    QObject::connect(this, &NewUserPage::createchats1, createP, &CreateChatPage::funcCreatechatpage1);

    QObject::connect(createP, &CreateChatPage::successfullyadded, this, &NewUserPage::addchat1);


}

User& NewUserPage:: fetchUser(){
    if(id==1)
        return (SystemManager::getInstance().currentuser1);
    else
        return(SystemManager::getInstance().currentuser2);
}







NewUserPage::~NewUserPage()
{
    delete ui;
}

void NewUserPage::updateLabel() {
    ///Update your label with the provided text
    if(!SystemManager::getInstance().getuser1().displayed){
        ui->UserLabel->setText(QString::fromStdString(fetchUser().getName()));
        SystemManager::getInstance().getuser1().displayed = true;
    }else{
        ui->UserLabel->setText(QString::fromStdString(fetchUser().getName()));
        SystemManager::getInstance().getuser2().displayed = true;
    }
}


void NewUserPage::addchat1(int i){

    cout << "addchat1 begin" << endl;
    bool found;

    Chat* chatptr = SystemManager::getInstance().chatmap.search(found,i);
    LinkedList<User> list = chatptr->getUsers();
    LinkedList<User>::Node* lptr = list.first;
    string chatname;
    while (lptr!= nullptr){//changehere
        if (lptr->data.getUserID() != fetchUser().getUserID() ){
            chatname.append(lptr->data.getName());
            chatname.append(", ");
        }
        lptr = lptr->next;
    }
    chatname.pop_back();
    chatname.pop_back();

    QPushButton *button = new QPushButton(QString::fromStdString(chatname));
    button->setObjectName(QString::number(i));
    //currentChatId = button->objectName().toInt();
    connect(button, &QPushButton::clicked, this, &NewUserPage::onChatButtonClicked);

    ui->ChatsLayout->addWidget(button);
    cout << "addchat1 end" << endl;
}



void NewUserPage::updatechatbtns() {
    cout << "updatechatbtns begin" << endl;

    // Clear the existing buttons from ChatsLayout
    clearChatsLayout();

    Hmap<Chat> chat = SystemManager::getInstance().DisplayUserChats1(fetchUser().getUserID());
    cout << "++++++++++++++"<<endl;
     SystemManager::getInstance().DisplayUserChats1(fetchUser().getUserID()).display();


    for (int i = 0; i < 11; i++) {
        Hmap<Chat>::Node* ptr = chat.table[i];
        while (ptr != nullptr) {
            LinkedList<User>::Node* lptr = ptr->value.users.first;
            string chatname;

            while (lptr != nullptr) {
                if (lptr->data.getUserID() != fetchUser().getUserID()) {
                    chatname.append(lptr->data.getName());
                    chatname.append(", ");
                }
                lptr = lptr->next;
            }

            chatname.pop_back();
            chatname.pop_back();

            QPushButton* button = new QPushButton(QString::fromStdString(chatname));
            button->setObjectName(QString::number(ptr->value.getChatID()));
            connect(button, &QPushButton::clicked, this, &NewUserPage::onChatButtonClicked);
            ui->ChatsLayout->addWidget(button);

            cout << ptr->value;
            ptr = ptr->next;
        }

    }

    cout << "updatechatbtns end" << endl;
}

void NewUserPage::clearChatsLayout() {
    // Clear all widgets in ChatsLayout
    QLayoutItem* child;
    while ((child = ui->ChatsLayout->takeAt(0)) != nullptr) {
        if (child->layout()) {
            // Recursively clear layouts
            clearLayout(child->layout());
        } else if (child->widget()) {
            // Remove and delete widgets
            delete child->widget();
        }
        delete child;
    }
}





void NewUserPage::updatechatbtns2() {
    cout << "updatechatbtns2 begin" << endl;

    // Clear the existing buttons from ChatsLayout
    clearChatsLayout();

    Hmap<Chat> chat2 = SystemManager::getInstance().DisplayUserChats2(SystemManager::getInstance().getuser2().getUserID());

    for (int i = 0; i < 11; i++) {
        Hmap<Chat>::Node* ptr = chat2.table[i];
        while (ptr != nullptr) {
            LinkedList<User>::Node* lptr = ptr->value.users.first;
            string chatname;

            while (lptr != nullptr) {
                if (lptr->data.getUserID() != fetchUser().getUserID()) {
                    chatname.append(lptr->data.getName());
                    chatname.append(", ");
                }
                lptr = lptr->next;
            }

            chatname.pop_back();
            chatname.pop_back();

            QPushButton* button = new QPushButton(QString::fromStdString(chatname));
            button->setObjectName(QString::number(ptr->value.getChatID()));
            connect(button, &QPushButton::clicked, this, &NewUserPage::onChatButtonClicked);

            ui->ChatsLayout->addWidget(button);

            cout << ptr->value;
            ptr = ptr->next;
        }
    }

    cout << "updatechatbtns2 end" << endl;
}


void NewUserPage::onChatButtonClicked() {
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender()); // Get the sender object
    if (clickedButton) {
        QString chatID = clickedButton->objectName(); // Get the object name (chat ID)

    bool found = false;
    Chat* ptr = SystemManager::getInstance().chatmap.search(found , chatID.toInt());
    if(found){
        ui -> widgett->show();
        ui->AllMessagesW->show();
        ui->sendMessageW->show();
        ui->scrollArea->show();

        LinkedList<User> :: Node* lptr = ptr->users.first;
        string chatname ;
        while (lptr!= nullptr){
            if (lptr->data.getUserID() != fetchUser().getUserID() ){
                chatname.append(lptr->data.getName());
                chatname.append(", ");
            }
            lptr = lptr->next;
        }
        chatname.pop_back();
        chatname.pop_back();
        ui -> chatNameLabel->setText(QString:: fromStdString(chatname));
        displayMessage(ptr);
        currentChatId = ptr->getChatID();
//hena
    }
    else
        cout << "chat id not found" << endl;

    }
}
void NewUserPage::on_AddAccountBtn_clicked()
{
    cout << "addaccount begin" << endl;
    if(!(SystemManager::getInstance().getuser1().displayed && SystemManager::getInstance().getuser2().displayed)){
        AddAccountPage *pge = new AddAccountPage();
        pge->show();
    }
    cout << "addaccount end" << endl;
}


void NewUserPage::on_AddChatBtn_clicked()
{   cout << "addchatbtn begin" << endl;
    if(!done){
    createP->show();
    emit createchats1(this->id); //parameter userid?
    done = true;
    }else{
      createP->show();
    }
    cout << "addchatbtn end" << endl;
}



//QVBoxLayout* mainlayout = new QVBoxLayout(NewUserPage :: ui -> AllMessagesW);


void NewUserPage::displayMessage(Chat* chatptr) {


    ui->AllMessagesW->setLayout(nullptr);
    clearMainLayout();

    LinkedList<Message>::Node* messageptr = chatptr->chatMessages.first;
\
    while (messageptr != nullptr) {
        string sendername;
        string content;
        string timeStamp;

        bool found = false;
        // current user 1 or 2
        if (messageptr->data.getSenderID() != fetchUser().getUserID()) {
            cout << "aligned left\n";
            User* ptrr = SystemManager::getInstance().usermap.search(found, messageptr->data.getSenderID());
            sendername = ptrr->getName();

            content = messageptr->data.getContent();
            timeStamp = messageptr->data.getTimeStamp();
        } else {
            cout << "aligned right\n";
            sendername = "me";
            content = messageptr->data.getContent();
            timeStamp = messageptr->data.getTimeStamp();
        }

        // Create a new QVBoxLayout for each message
        QVBoxLayout* messageLayout = new QVBoxLayout();
        messageLayout->setSpacing(2);
        messageLayout->setContentsMargins(20, 20, 20, 20);

        if (messageptr->data.getSenderID() != fetchUser().getUserID()) {
            messageLayout->setAlignment(Qt::AlignLeft);
        } else {
            messageLayout->setAlignment(Qt::AlignRight);
        }

        QLabel* namee = new QLabel(QString::fromStdString(sendername));
        QLabel* timeStampp = new QLabel(QString::fromStdString(timeStamp));
        QLabel* Content = new QLabel(QString::fromStdString(content));
        namee->setStyleSheet("background-color: #d2f2f7;");

        messageLayout->addWidget(namee);
        messageLayout->addWidget(timeStampp);
        messageLayout->addWidget(Content);
        mainlayout->addLayout(messageLayout);

        messageptr = messageptr->next;
    }
    mainlayout->setParent(ui->AllMessagesW);


}

void NewUserPage::clearMainLayout() {
    QLayoutItem* child;
    while ((child = mainlayout->takeAt(0)) != nullptr) {
        if (child->layout()) {
            // Recursively clear layouts
            clearLayout(child->layout());
        } else if (child->widget()) {
            // Remove and delete widgets
            delete child->widget();
        }
        delete child;
    }
}

void NewUserPage::clearLayout(QLayout* layout) {
    QLayoutItem* child;
    while ((child = layout->takeAt(0)) != nullptr) {
        if (child->layout()) {
            // Recursively clear layouts
            clearLayout(child->layout());
        } else if (child->widget()) {
            // Remove and delete widgets
            delete child->widget();
        }
        delete child;
    }
}




//send
void NewUserPage::on_sendMsgButton_clicked()
{

    QString QmessageContent = ui->messageContentInput->toPlainText();
    string messageContent = QmessageContent.toStdString();
    ui->messageContentInput->clear();
    int senderID = fetchUser().getUserID();
    int chatID = currentChatId;

    Message m(messageContent, senderID);

    SystemManager::getInstance().sendMessage(chatID,  m);

    bool found = false;
    Chat* ptr = SystemManager :: getInstance().chatmap.search(found , chatID);

    displayMessage(ptr);

}



void NewUserPage::on_LogoutBtn_clicked()
{
    SystemManager::getInstance().writeToFileMessages();
    SystemManager::getInstance().writeToFileUser();
    SystemManager::getInstance().writeToFileChat();
    hide();

}





void NewUserPage::on_RefreshBtn_clicked()
{
    if(id==1){
        cout << "-------------------------------------\n";
        updatechatbtns();
    }
    else{
        cout << "============================= didntwork";
        updatechatbtns2();
    }

}

