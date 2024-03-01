#include "addaccountpage.h"
#include "ui_addaccountpage.h"
#include "SystemManager.hpp"
AddAccountPage::AddAccountPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddAccountPage)
{
    ui->setupUi(this);
    upage1 = new NewUserPage();
    upage1->id =2;
    QObject::connect(this, &AddAccountPage::successfulLogin, upage1, &NewUserPage::updateLabel);
    QObject::connect(this, &AddAccountPage::successfulchats2, upage1, &NewUserPage::updatechatbtns2);

}

AddAccountPage::~AddAccountPage()
{
    delete ui;
}

void AddAccountPage::on_LoginToAccBtn_clicked()
{
    QString name = ui->LoginUsername->toPlainText();
    QString pass = ui->LoginPassword->toPlainText();

    //SystemManager::getInstance().readFromFileUser();
    User user2;
    bool isfound = SystemManager::getInstance().login(name.toStdString(), pass.toStdString(), user2);
    if(isfound){
        hide();
        upage1->show();
        SystemManager::getInstance().setuser2(user2);
        emit successfulLogin();
        emit successfulchats2();
    }else{
        ui->Isfound_Label->setText("Incorrect Password");
    }
}

