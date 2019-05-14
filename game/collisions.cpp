#include "collisions.hpp"


Collisions::Collisions(Ball * ball, Scene * scene)
    : ball_ (ball)
    , scene_(scene)
{
    assert(ball);
    connect(ball_, &Ball::destroyed, this, &Collisions::deleteLater);
    connect(Clock::instance(), Clock::instance()->getTimerSignalDt(ball->dt()),
            this, &Collisions::update);
}


Collisions::~Collisions()
{
    disconnect(ball_, &Ball::destroyed, this, &Collisions::deleteLater);
}


void Collisions::update(Time dt)
{
    Q_UNUSED(dt)
    assert(ball_);
    assert(scene_);

    if (auto n = scene_->intersectsWithTable(ball_)) {
        ball_->reflect(n.value());
    } else if (auto n = scene_->intersectsWithGrid(ball_)) {
        ball_->reflect(n.value());
    }
}
