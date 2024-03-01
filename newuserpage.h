#ifndef NEWUSERPAGE_H
#define NEWUSERPAGE_H

#include <QDialog>
#include "createchatpage.h"
#include "SystemManager.hpp"
#include "QVBoxLayout"
namespace Ui {
class NewUserPage;
}

class NewUserPage : public QDialog
{
    Q_OBJECT

public:
    explicit NewUserPage(QWidget *parent = nullptr);
    User& fetchUser();
    ~NewUserPage();
    QVBoxLayout* mainlayout;
    void clearMainLayout();
    void clearChatsLayout();
    int currentChatId;
    void clearLayout(QLayout* layout);
    int id;
    bool done = false;
public slots:
    void updateLabel();
    void updatechatbtns();
    void updatechatbtns2();
    void addchat1(int i);
private slots:
    void onChatButtonClicked();
    void on_AddAccountBtn_clicked();
    void on_sendMsgButton_clicked();
    void on_AddChatBtn_clicked();
    //void on_sendMsgButton_clicked();
    void  displayMessage(Chat* chatptr);
    void on_LogoutBtn_clicked();

    void on_RefreshBtn_clicked();

signals:
    void createchats1(int id);


private:
    Ui::NewUserPage *ui;
    CreateChatPage *createP;
    QVBoxLayout* mainLayout;



};

#endif // NEWUSERPAGE_H
