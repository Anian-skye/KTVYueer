#include "songmanage.h"

SongManage::SongManage()
{
   list = new QMediaPlaylist;

}


void SongManage::addSong(QString path,QString name){
   SongList[name]=path;
}


QString SongManage::getSong(QString name){
    return SongList[name];
}


