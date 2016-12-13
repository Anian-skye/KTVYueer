#include "singing.h"
#include "ui_singing.h"

Singing::Singing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Singing)
{
    ui->setupUi(this);
}

Singing::~Singing()
{
    delete ui;
}
