#include "camflyingaround.hpp"


CamFlyingAround::CamFlyingAround(Qt3DRender::QCamera * camera, float radious,
                                 int fps, float dt)
    : camera_(camera)
    , r_     (radious)
    , dt_    (dt)
{
    assert(camera);
    assert(radious >= 0);
    assert(fps > 0);

    startTimer(1 / fps * 1000);
    timerEvent(nullptr);
}


void CamFlyingAround::timerEvent(QTimerEvent * event)
{
    Q_UNUSED(event)

    t_ += dt_;
    auto a = camera_->viewCenter().x();
    auto b = camera_->viewCenter().z();

    auto x = a + r_ * std::cos(t_);
    auto y = camera_->position().y();
    auto z = b + r_ * std::sin(t_);

    camera_->setPosition({x, y, z});
}
