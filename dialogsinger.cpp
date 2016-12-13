#include "dialogsinger.h"
#include "ui_dialogsinger.h"

dialogSinger::dialogSinger(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogSinger)
{
    ui->setupUi(this);
    ui->songListTab->setColumnWidth(0,429);
    ui->songListTab->setColumnWidth(1,100);


    sflag=0;
}

dialogSinger::~dialogSinger()
{
    delete ui;
}

void dialogSinger::on_pushButton_clicked()
{
    ui->singerList->hide();
    ui->songList->show();
    sflag=1;
}

void dialogSinger::on_fanhui_clicked()
{
    if(sflag==0)
    {
        this->close();
    }
    if(sflag==1)
    {
        ui->songList->hide();
        ui->singerList->show();
        sflag=0;
    }
}

void dialogSinger::on_pushButton_2_clicked()
{
    ui->singerList->hide();
    ui->songList->show();
    sflag=1;
}

void dialogSinger::on_pushButton_4_clicked()
{
    ui->singerList->hide();
    ui->songList->show();
    sflag=1;
}

void dialogSinger::on_pushButton_6_clicked()
{
    ui->singerList->hide();
    ui->songList->show();
    sflag=1;
}

void dialogSinger::on_pushButton_5_clicked()
{
    ui->singerList->hide();
    ui->songList->show();
    sflag=1;
}

void dialogSinger::on_pushButton_3_clicked()
{
    ui->singerList->hide();
    ui->songList->show();
    sflag=1;
}
