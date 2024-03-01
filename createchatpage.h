#ifndef CREATECHATPAGE_H
#define CREATECHATPAGE_H

#include <QDialog>

namespace Ui {
class CreateChatPage;
}

class CreateChatPage : public QDialog
{
    Q_OBJECT

public:
    explicit CreateChatPage(QWidget *parent = nullptr);
    ~CreateChatPage();
    int id1;
public slots:
    void funcCreatechatpage1(int id);
private slots:
    void on_CreateBtn_clicked();

signals:
    void successfullyadded(int i);

private:
    Ui::CreateChatPage *ui;
};

#endif // CREATECHATPAGE_H
