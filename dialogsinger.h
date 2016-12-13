#ifndef DIALOGSINGER_H
#define DIALOGSINGER_H

#include <QDialog>

namespace Ui {
class dialogSinger;
}

class dialogSinger : public QDialog
{
    Q_OBJECT

public:
    explicit dialogSinger(QWidget *parent = 0);
    ~dialogSinger();

private slots:
    void on_pushButton_clicked();

    void on_fanhui_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::dialogSinger *ui;
    int sflag;
};

#endif // DIALOGSINGER_H
