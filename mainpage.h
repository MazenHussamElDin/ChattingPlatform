#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QDialog>
#include "loginpage.h"
#include "signuppage.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainPage;
}
QT_END_NAMESPACE

class MainPage : public QDialog
{
    Q_OBJECT

public:
    MainPage(QWidget *parent = nullptr);
    ~MainPage();

private slots:


    void on_GoToLoginBtn_clicked();
    void on_GoToSignupBtn_clicked();

private:
    Ui::MainPage *ui;
    LoginPage *loginpage;
    SignupPage *signuppage;
};
#endif // MAINPAGE_H
