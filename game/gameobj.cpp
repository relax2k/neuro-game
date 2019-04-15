#include "gameobj.hpp"

#include <QDebug>


QVector3D GameObj::getPos() const
{
//    qDebug() << "I'm getter";
    return position;
}


void GameObj::setPos(QVector3D pos)
{
//    qDebug() << "I'm setter";
    position = pos;
    emit posChanged();
}
