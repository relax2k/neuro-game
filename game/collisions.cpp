#include "collisions.hpp"


Collisions::Collisions(Ball * ball, Scene * scene)
    : ball_ (ball)
    , scene_(scene)
{
    assert(ball);

    startTimer(2 * ball->dt()); // To prevent twice collision processing

    connect(ball_, &Ball::destroyed, this, &Collisions::deleteLater);
}


Collisions::~Collisions()
{
    disconnect(ball_, &Ball::destroyed, this, &Collisions::deleteLater);
}


void Collisions::timerEvent(QTimerEvent * event)
{
    Q_UNUSED(event)
    assert(ball_);
    assert(scene_);

    if (auto n = scene_->intersectsWithTable(ball_)) {
        ball_->reflect(n.value());
    } else if (auto n = scene_->intersectsWithGrid(ball_)) {
        ball_->reflect(n.value());
    }
}
