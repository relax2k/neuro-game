#pragma once

#include "scene.hpp"
#include "ball.hpp"


class Collisions final
        : public QObject {
    Q_OBJECT

public:
    Collisions(Ball * ball, Scene * scene);
    ~Collisions() override;

private:
    void timerEvent(QTimerEvent * event) override;

private:
    Ball  * ball_;
    Scene * scene_;
};
