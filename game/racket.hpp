#pragma once

#include "stdafx.hpp"


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
    void runAnimation1(QVector3D endPos, int time);
    void runAnimation2(QVector3D endPos, int time);

private:
    Qt3DCore::QEntity * entity_;
    Qt3DCore::QTransform * transform_;
};

