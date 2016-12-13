#ifndef SINGING_H
#define SINGING_H

#include <QDialog>

namespace Ui {
class Singing;
}

class Singing : public QDialog
{
    Q_OBJECT

public:
    explicit Singing(QWidget *parent = 0);
    ~Singing();

private:
    Ui::Singing *ui;
};

#endif // SINGING_H
