#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include "dialogsinger.h"
#include "songmanage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_Button_singer_clicked();

    void on_change_button_clicked();

    void on_stop_start_button_clicked();


    void on_show_list_button_clicked();

    void on_pushButton_3_clicked();

    void on_volume_sliderMoved(int position);

    void on_next_button_clicked();

    void on_restart_button_clicked();

  /*  void on_song_list_itemDoubleClicked(QTableWidgetItem *item);*/

    void on_song_list_itemClicked(QTableWidgetItem *item);



    void on_showsong_button_clicked();

    void updateSongList(int);


    void on_songed_list_itemClicked(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;
    dialogSinger Dsinger;
    QMediaPlayer *player;
    //QMediaPlaylist *list;
    //QVideoWidget *videoWidget;
    QSettings *configIniWrite; //配置文件写指针
    QSettings *configIniRead; //配置文件写指针
    SongManage *songManage;
    int yflag;
    int ssflag;
    int sflag;
    int vflag;
    int currentIndex;
};

#endif // MAINWINDOW_H
