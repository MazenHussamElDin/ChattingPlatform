#ifndef ADDACCOUNTPAGE_H
#define ADDACCOUNTPAGE_H

#include <QDialog>
#include "newuserpage.h"

namespace Ui {
class AddAccountPage;
}

class AddAccountPage : public QDialog
{
    Q_OBJECT

public:
    explicit AddAccountPage(QWidget *parent = nullptr);
    ~AddAccountPage();

private slots:
    void on_LoginToAccBtn_clicked();


signals:
    void successfulLogin();
    void successfulchats2();
private:
    Ui::AddAccountPage *ui;
    NewUserPage *upage1;


};

#endif // ADDACCOUNTPAGE_H
