#pragma once

#include "ball.hpp"


class Scene;

class Collisions final
        : public QObject {
    Q_OBJECT

public:
    Collisions(Ball * ball, Scene * scene);
    ~Collisions() override;

private slots:
    void update(Time dt);
    void harakiri();

private:
    Ball  * ball_;
    Scene * scene_;
};
