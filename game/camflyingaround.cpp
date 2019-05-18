#include "camflyingaround.hpp"


CamFlyingAround::CamFlyingAround(Qt3DRender::QCamera * camera,
                                 float radious, float dt)
    : camera_(camera)
    , r_     (radious)
    , dt_    (dt)
{
    assert(camera);
    assert(radious >= 0);

    startTimer(15); // ~60 fps
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
