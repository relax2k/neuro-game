#include "gameobj.hpp"

#include <QDebug>


QVector3D GameEntity::getPos() const
{
    return position;
}


void GameEntity::setPos(QVector3D pos)
{
    position = pos;
    emit posChanged();
}
