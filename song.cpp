#include "song.h"

Song::Song(int status,QStringList path,QString name)
{
    this->status = status;
    this->path = path;
    this->name = name;
}


void Song::setStatus(int status){
    this->status=status;
}
