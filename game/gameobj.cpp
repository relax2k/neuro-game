#include "gameobj.hpp"

#include <QDebug>


QVector3D GameObj::getPos() const
{
    return position;
}


void GameObj::setPos(QVector3D pos)
{
    position = pos;
    emit posChanged();
}
