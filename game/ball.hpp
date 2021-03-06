#pragma once

#include "stdafx.hpp"
#include "scene.hpp"
#include "time.hpp"


class Ball final
        : public QObject {
    Q_OBJECT

public:
    using Interval = std::optional<std::pair<qreal, qreal>>;

    explicit Ball(Qt3DCore::QEntity * parent);
    /**
      * @warning Ball should not be deleted after parent.
      */
    ~Ball() override;

    void setV(QVector3D v);
    void setV(QVector3D newPos, Time dt);
    QVector3D v() const;

    void setGravity(bool b);
    bool gravity() const;

    void setPos(QVector3D pos);
    QVector3D pos() const;
    /**
     * @brief Preicts ball's position.
     * @param dt Time interval in ms.
     * @return Ball's position in dt seconds.
     */
    QVector3D predictPos(Time dt);

    float radius() const;
    Time dt() const;

    /**
     * @brief Chages ball's speed as if it reflected.
     * @param n Normal of surface ball collided with.
     */
    void reflect(QVector3D n);

    void setBorderCrossNotifier(Interval l);

private:
    void applyGravity();
    void move();
    bool isInInterval() const;

private slots:
    void update(Time dt);

signals:
    void borderCrossed(bool crossedInto);
    void reflected(QVector3D newV);

private:
    const QVector3D g_ = QVector3D{0, -9.8f, 0};
    const float radius_ = 0.1f;

    Qt3DCore::QEntity    * entity_;
    Qt3DCore::QTransform * transform_;

    QVector3D v_{};
    bool gravity_ = false;
    Interval xint_;
    bool inInterval_{};
    Time dt_ = Clock::dt60;
};
