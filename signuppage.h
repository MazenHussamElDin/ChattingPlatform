#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QDialog>

namespace Ui {
class SignupPage;
}

class SignupPage : public QDialog
{
    Q_OBJECT

public:
    explicit SignupPage(QWidget *parent = nullptr);
    ~SignupPage();

private slots:
    void on_BackToMainPageBtn_clicked();

    void on_SignupBtn_clicked();

private:
    Ui::SignupPage *ui;
};

#endif // SIGNUPPAGE_H
