#pragma once

#include "stdafx.hpp"
#include "defs.hpp"
#include "scene.hpp"


class Ball final
        : public QObject {
    Q_OBJECT

public:
    explicit Ball(Qt3DCore::QEntity * parent, int dt = UPDATE_INTERVAL);
    /**
      * @warning Ball should not be deleted after parent.
      */
    ~Ball() override;

    void setV(QVector3D v);
    QVector3D v() const;

    void setGravity(bool b);
    bool gravity() const;

    void setPos(QVector3D pos);
    QVector3D pos() const;

private:
    void timerEvent(QTimerEvent * event) override;
    void applyGravity();
    void move();

    float toSec(int t) const;

private:
    const QVector3D g_ = QVector3D{ 0, -980, 0 } * Scene::SCALE;

    Qt3DCore::QEntity    * entity_;
    Qt3DCore::QTransform * transform_;

    QVector3D v_{};
    bool gravity_ = false;
    int dt_;
};
