#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>
#include "newuserpage.h"

namespace Ui {
class LoginPage;
}

class LoginPage : public QDialog
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private slots:
    void on_BackToMainPageBtn_clicked();

    void on_LoginToAccBtn_clicked();

signals:
    void successfulLogin();
    void successfulchats();
private:
    Ui::LoginPage *ui;
    NewUserPage *upage;


};

#endif // LOGINPAGE_H
