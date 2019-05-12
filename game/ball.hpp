#pragma once

#include "stdafx.hpp"
#include "defs.hpp"


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

    void setGravity(bool b = true);
    bool gravity() const;

    void setPos(QVector3D pos);
    QVector3D pos() const;

private:
    void timerEvent(QTimerEvent * event) override;
    void applyGravity();
    void move();

private:
    const float g_ = 9.8f;

    Qt3DCore::QEntity    * entity_;
    Qt3DCore::QTransform * transform_;

    QVector3D v_{};
    bool gravity_ = true;
    int dt_;
};
