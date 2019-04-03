#include "camera.hpp"


void Camera::move(double dt) const
{
    position() += v_ * dt;
}


void Camera::moveAround(double dt) const
{
    // TODO(Yuki/Camera::moveAround)
//    position()
}
