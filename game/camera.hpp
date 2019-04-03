#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <Qt3DRender/QCamera>

#include "gameobj.hpp"


class Camera
        : public Qt3DRender::QCamera
{
    Q_OBJECT

public:
    Camera() = default;

    void move(double dt) const;
    void moveAround(double dt) const;

    QVector3D const & getV() const { return v_; }
    void setV(QVector3D vec) { v_ = vec; }

private:
    QVector3D v_ = {0, 0, 0};
};


#endif // CAMERA_HPP
