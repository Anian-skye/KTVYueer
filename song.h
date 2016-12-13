#ifndef SONG_H
#define SONG_H

#include <QStringList>

class Song
{
private:   
    int status;
    QStringList path;
    QString name;

public:
    QStringList getPath(){return path;}
    int getStatus(){return status;}
    void setStatus(int status);
    Song(int status,QStringList path,QString name);
};

#endif // SONG_H
