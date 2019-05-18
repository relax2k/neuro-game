#pragma once

#include "stdafx.hpp"
#include "time.hpp"


class Racket final
        : public QObject {
    Q_OBJECT

public:
    explicit Racket(Qt3DCore::QEntity * parent);
    /**
      * @warning Racket should not be deleted after parent.
      */
    ~Racket() override;

    void setPos(QVector3D pos);
    QVector3D pos() const;

    // TODO animation
    void runAnimation1(QVector3D endPos, Time dt);

signals:
    void animationFinished();

private:
    Qt3DCore::QEntity * entity_;
    Qt3DCore::QTransform * transform_;
};

