#ifndef SONGMANAGE_H
#define SONGMANAGE_H
#include <QMediaPlaylist>
#include <map>
#include <QString>

using namespace std;


class SongManage
{

private:

    map<QString,QString> SongList;

public:
    QMediaPlaylist *list;
    SongManage();
    void addSong(QString path,QString name);
    QString getSong(QString name);
};

#endif // SONGMANAGE_H
