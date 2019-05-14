#pragma once

#include "stdafx.hpp"
#include "scene.hpp"
#include "time.hpp"


class Ball final
        : public QObject {
    Q_OBJECT

public:
    using Interval = std::pair<std::optional<qreal>, std::optional<qreal>>;

    explicit Ball(Qt3DCore::QEntity * parent);
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
    float radius() const;
    Time dt() const;

    void reflect(QVector3D n);

    void outOfXIntervalNotifier(Interval l);

private:
    void applyGravity();
    void move();
    bool isInInterval() const;

    float toSec(Time t) const;

private slots:
    void update(Time dt);

signals:
    void outOfXInterval(qreal x);

private:
    const QVector3D g_ = QVector3D{ 0, -980, 0 } * Scene::SCALE;

    Qt3DCore::QEntity    * entity_;
    Qt3DCore::QTransform * transform_;

    QVector3D v_{};
    bool gravity_ = false;
    float radius_ = 20 * Scene::SCALE;
    Time dt_ = Clock::dt60;
    Interval xint_ = { std::nullopt, std::nullopt };
};
