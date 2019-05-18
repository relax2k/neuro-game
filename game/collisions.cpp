#include "collisions.hpp"

#include "table.hpp"


Collisions::Collisions(Ball * ball, Scene * scene)
    : ball_ (ball)
    , scene_(scene)
{
    assert(ball);
    assert(scene);

    // It should not be connected to deleteLater,
    // dtor will throw std::bad_alloc in disconnect.
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

    if (auto n = scene_->table()->intersects(ball_)) {
        ball_->reflect(n.value());
    }
}


void Collisions::harakiri()
{
    delete this;
}
