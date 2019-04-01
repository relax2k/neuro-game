#ifndef BALL_HPP
#define BALL_HPP

#include "gameobj.hpp"


class Ball
        : public GameObj
{
    Q_OBJECT

public:
    explicit Ball(QObject * parent = nullptr)
        : GameObj(parent) {}
};


#endif // BALL_HPP
