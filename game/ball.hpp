#ifndef BALL_HPP
#define BALL_HPP

#include "gameobj.hpp"


class Ball
        : public GameEntity
{
    Q_OBJECT

public:
    explicit Ball(QObject * parent = nullptr)
        : GameEntity(parent) {}
};


#endif // BALL_HPP
