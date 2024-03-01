#include "signuppage.h"
#include "ui_signuppage.h"
#include "mainpage.h"
#include "SystemManager.hpp"
#include "loginpage.h"
SignupPage::SignupPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignupPage)
{
    ui->setupUi(this);
}

SignupPage::~SignupPage()
{
    delete ui;
}

void SignupPage::on_BackToMainPageBtn_clicked()
{
    hide();
    MainPage *mp = new MainPage();
    mp->show();
}


void SignupPage::on_SignupBtn_clicked()
{

    if(ui->SignupPassword->toPlainText() == ui->SignupConfirmPassword->toPlainText()){
        QString name = ui->SignupUsername->toPlainText();
        QString pass = ui->SignupPassword->toPlainText();
        //SystemManager::getInstance().readFromFileUser();
        SystemManager::getInstance().addUser(name.toStdString(), pass.toStdString());


        SystemManager::getInstance().writeToFileUser();
        LoginPage *logp = new LoginPage();
        hide();
        logp->show();
    }else{
        ui->signup_Label->setText("Password Doesn't Match Try Again!");
    }




}

