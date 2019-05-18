#pragma once

#include "stdafx.hpp"


class CamFlyingAround final
        : public QObject {
    Q_OBJECT

public:
    CamFlyingAround(Qt3DRender::QCamera * camera,
                    float radious, float dt = 0.002f);
    void timerEvent(QTimerEvent * event) override;

private:
    Qt3DRender::QCamera * camera_;
    float r_;
    float dt_;
    float t_ = 0;
};
