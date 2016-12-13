#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <cstring>
#include <QTime>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setFixedSize(790,591);

    ui->bottom_button->setStyleSheet("background-color:rgba(244,244,244,95%)");
    ui->song_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->songed_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->song_list->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->song_list->setColumnWidth(0,199);
    ui->song_list->setColumnWidth(1,50);
    ui->song_list->setColumnWidth(2,50);
    ui->songed_list->setColumnWidth(0,250);
    ui->songed_list->setColumnWidth(1,50);
    ui->tabWidget->hide();
    ui->videoWidget->hide();
    ui->videoWidget->setWindowFlags(Qt::WindowStaysOnTopHint);

    qDebug()<<"success1";
    player = new QMediaPlayer;

    qDebug()<<"success2";
    qDebug()<<"success3";
    songManage = new SongManage;

    //videoWidget = new QVideoWidget;
    yflag=0;
    ssflag=0;
    sflag=0;
    vflag=0;
    currentIndex = 0;

    songManage->list->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(songManage->list);
    qDebug()<<"success4";


    //信号和槽相连

    connect(songManage->list, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSongList(int)));





    //打开用户保存的歌曲列表
    /*configIniRead = new QSettings("PlayList.ini", QSettings::IniFormat);
    QStringList songList;
    for(int i=0; ; ++i)
    {
        if(configIniRead->value("/song/"+QString::number(i),1000).toInt()!=1000)
        {
            QString path = configIniRead->value("/song/"+QString::number(i)).toString();
            songList.append(path);
            list->addMedia(QUrl::fromLocalFile(path));
            player->setVolume(ui->volume->value());
            QString fileName=path.split("\\").last();
            int rownum=ui->song_list->rowCount();
            ui->song_list->insertRow(rownum);
            ui->song_list->setItem(rownum, 0, new QTableWidgetItem(fileName.split(".").front()));
            ui->song_list->setItem(rownum, 1, new QTableWidgetItem(fileName.split(".").last()));

        }
        else
        {
            break;
        }
    }*/
    songManage->list->setCurrentIndex(currentIndex);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_singer_clicked()
{
     this->hide();
     Dsinger.show();
     Dsinger.exec();
     this->show();
}

void MainWindow::on_change_button_clicked()
{
    if(yflag==0)
    {
        ui->change_button->setIcon(QIcon(":/new/prefix1/images/banchang.png"));
        yflag=1;
    }
    else if(yflag==1){
       ui->change_button->setIcon(QIcon(":/new/prefix1/images/yuanchang.png"));
       yflag=0;
    }
}

void MainWindow::on_stop_start_button_clicked()   //开始暂停
{
    if(ssflag==0)
    {
        ui->stop_start_button->setIcon(QIcon(":/new/prefix1/images/start.png"));
        if(player->position()==0)
        {
           player->setVideoOutput(ui->videoWidget);
           songManage->list->setCurrentIndex(currentIndex);
           player->play();
        }
        else
        {
            player->play();
        }

        ssflag=1;

    }
    else if(ssflag==1){
       ui->stop_start_button->setIcon(QIcon(":/new/prefix1/images/stop.png"));
       player->pause();
       ssflag=0;
    }
}



void MainWindow::on_show_list_button_clicked()   //显示歌单
{
    if(sflag==0)
    {
    ui->tabWidget->show();
    sflag=1;
    }
    else if(sflag==1)
    {
        ui->tabWidget->hide();
        sflag=0;
    }


}

void MainWindow::on_pushButton_3_clicked()
{
    configIniWrite = new QSettings("PlayList.ini", QSettings::IniFormat);
    QStringList pathList=QFileDialog::getOpenFileNames(this, tr("选择文件"), ".", "Multimedia (*.mp3 *.wmv *.mp4);;All files (*.*)");
    for(int i=0; i<pathList.size(); ++i)
    {
        QString path=QDir::toNativeSeparators(pathList.at(i));
        if(!path.isEmpty())
        {
            songManage->list->addMedia(QUrl::fromLocalFile(path));
            player->setVolume(ui->volume->value());
            QString fileName=path.split("\\").last();
            int rownum=ui->song_list->rowCount();
            ui->song_list->insertRow(rownum);
            QTableWidgetItem *item = new QTableWidgetItem(fileName.split(".").front());
            item->setText(fileName.split(".").front());
            qDebug()<<item->text();
            ui->song_list->setItem(rownum, 0, item);
            ui->song_list->setItem(rownum, 1, new QTableWidgetItem(QIcon(":/new/prefix1/images/delete_201px_1189401_easyicon.net.png"),""));
            item->setText(fileName.split(".").front());
            ui->song_list->setItem(rownum, 2, new QTableWidgetItem(QIcon(":/new/prefix1/images/long_arrow_up_668px_1190640_easyicon.net.png"),""));
            //configIniWrite->setValue("/song/"+QString::number(rownum), path);//保存歌曲列表
            songManage->addSong(path,fileName.split(".").front());
            qDebug()<<path;
        }

    }


}

void MainWindow::on_volume_sliderMoved(int position)  //音量控制
{
    player->setVolume(position);
}

void MainWindow::on_next_button_clicked()  //下一首
{
    if(++currentIndex==songManage->list->mediaCount()) currentIndex=0;
        player->setVideoOutput(ui->videoWidget);
        ui->videoWidget->show();
        songManage->list->setCurrentIndex(currentIndex);
        player->play();

}

void MainWindow::on_restart_button_clicked()          //重唱
{
    player->stop();
    songManage->list->setCurrentIndex(currentIndex);
    player->play();
}

/*void MainWindow::on_song_list_itemDoubleClicked(QTableWidgetItem *item)    //双击列表播放
{
    int flag=item->column();
    if(flag==0)
   {
      currentIndex = item->row();
      songManage->list->setCurrentIndex(currentIndex);
      ui->stop_start_button->setIcon(QIcon(":/new/prefix1/images/start.png"));
      ssflag=!ssflag;
      player->play();
    }
    else return;
}*/


void MainWindow::on_song_list_itemClicked(QTableWidgetItem *item)  //删除和顶歌
{
    int flag = item->column();
    qDebug()<<"lalala1";
    QTableWidgetItem *tempUp,*tempDe;
    qDebug()<<"lalala2";
    if(flag == 1){
        tempDe=ui->song_list->item(item->row(),item->column()-1);
        QString text = tempDe->text();
        if(item->row()==0){
             int rownum=ui->songed_list->rowCount();
             qDebug()<<rownum;
             ui->songed_list->insertRow(0);
             qDebug()<<text;
             QTableWidgetItem *ite = new QTableWidgetItem(text);
             ui->songed_list->setItem(0, 0, new QTableWidgetItem(text));
             ite->setText(text);
             ui->songed_list->setItem(0,1,new QTableWidgetItem(QIcon(":/new/prefix1/images/icon/Power_Restart_256px_1072611_easyicon.net.png"),""));
        }
        songManage->list->removeMedia(item->row());
        ui->song_list->removeRow(item->row());
    }
    else if(flag==2){
       /*for(int i=0;i<temp->column()-1;i++){
           ui->song_list->setItem(item->row(),0,--item);
       }*/
       tempUp=ui->song_list->item(item->row(),item->column()-2);
       qDebug()<<tempUp->text();
       ui->song_list->insertRow(1);
       ui->song_list->setItem(1, 0, new QTableWidgetItem(tempUp->text()));
       ui->song_list->setItem(1, 1, new QTableWidgetItem(QIcon(":/new/prefix1/images/delete_201px_1189401_easyicon.net.png"),""));
       ui->song_list->setItem(1, 2, new QTableWidgetItem(QIcon(":/new/prefix1/images/long_arrow_up_668px_1190640_easyicon.net.png"),""));
       qDebug()<<item->row();
       songManage->list->insertMedia(1,songManage->list->media(item->row()-1));
       songManage->list->removeMedia(item->row());
       ui->song_list->removeRow(item->row());
    }
    else if(flag==0)
    {
        qDebug()<<"选中歌曲";
    }
}




void MainWindow::on_showsong_button_clicked()
{
    if(vflag==0){
    ui->videoWidget->show();
    ui->widget_2->hide();
    ui->widget->hide();
    vflag=1;
    }
    else if(vflag==1){
       ui->videoWidget->hide();
       ui->widget_2->show();
       ui->widget->show();
        vflag=0;
    }
}

void MainWindow::updateSongList(int i)
{
    if(i!=0)
    {
    QTableWidgetItem *item = ui->song_list->item(0,0);
    ui->songed_list->insertRow(0);
    QTableWidgetItem *ite = new QTableWidgetItem(item->text());
    ui->songed_list->setItem(0, 0,ite);
    ui->songed_list->setItem(0,1,new QTableWidgetItem(QIcon(":/new/prefix1/images/icon/Power_Restart_256px_1072611_easyicon.net.png"),""));
    ite->setText(item->text());
    ui->song_list->removeRow(0);
    songManage->list->setCurrentIndex(i);
    }
    else
    {
        qDebug()<<"new";
        songManage->list->setCurrentIndex(i);
    }

}



void MainWindow::on_songed_list_itemClicked(QTableWidgetItem *item)
{
     int flag = item->column();
     QTableWidgetItem *temp=ui->songed_list->item(item->row(),item->column()-1);
     QString name = temp->text();
     //QString path = songManage->getSong(name);
     //songManage->list->addMedia(QUrl::fromLocalFile(path));
     int rownum=ui->song_list->rowCount();
     ui->song_list->insertRow(rownum);
     ui->song_list->setItem(rownum,0,new QTableWidgetItem(name));


}
