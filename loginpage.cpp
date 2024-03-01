#include "ui_loginpage.h"
#include "loginpage.h"
#include "mainpage.h"
#include <string>
#include "QString"
#include "SystemManager.hpp"
using namespace std;
LoginPage::LoginPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    upage = new NewUserPage();
    upage->id = 1;
    QObject::connect(this, &LoginPage::successfulLogin, upage, &NewUserPage::updateLabel);
    QObject::connect(this, &LoginPage::successfulchats, upage, &NewUserPage::updatechatbtns);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_BackToMainPageBtn_clicked()
{
    hide();
    MainPage *mp = new MainPage();
    mp->show();


}


void LoginPage::on_LoginToAccBtn_clicked()
{
    QString name = ui->LoginUsername->toPlainText();
    QString pass = ui->LoginPassword->toPlainText();

   // SystemManager::getInstance().readFromFileUser();
    User user1;
    bool isfound = SystemManager::getInstance().login(name.toStdString(), pass.toStdString(), user1);
    if(isfound){
        hide();
        upage->show();
        SystemManager::getInstance().setuser1(user1);
        emit successfulLogin();
        emit successfulchats();
    }else{
        ui->Isfound_Label->setText("Incorrect Password");
    }

}

