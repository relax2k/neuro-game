#include "collisions.hpp"


Collisions::Collisions(Ball * ball, Scene * scene)
    : ball_ (ball)
    , scene_(scene)
{
    assert(ball);
    // It should not be connected to deleteLater, dtor will throw
    // std::bad_alloc in disconnect.
    connect(ball_, &Ball::destroyed, this, &Collisions::harakiri);
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

    auto n1 = scene_->intersectsWithTable(ball_);
    if (n1.second) {
        ball_->reflect(n1.first);
    }

    auto n2 = scene_->intersectsWithGrid(ball_);
    if (n2.second) {
        ball_->reflect(n2.first);
    }
}


void Collisions::harakiri()
{
    delete this;
}
