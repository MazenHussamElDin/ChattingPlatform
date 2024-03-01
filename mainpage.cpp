#include "mainpage.h"
#include "./ui_mainpage.h"

MainPage::MainPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainPage)
{
    ui->setupUi(this);
    QPixmap pixmap("G:/Semester 5/Data Structures/Project/untitledehab/WhatsApp Image 2023-12-31 at 12.33.59_8f62e046.jpg");
    ui->pic_Label->setPixmap(pixmap);

}

MainPage::~MainPage()
{
    delete ui;
}





void MainPage::on_GoToLoginBtn_clicked()
{
    hide();
    loginpage = new LoginPage(this);
    loginpage->show();
}



void MainPage::on_GoToSignupBtn_clicked()
{

    hide();
    signuppage = new SignupPage();
    signuppage->show();
}

