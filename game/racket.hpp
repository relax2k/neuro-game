#pragma once

#include "stdafx.hpp"
#include "defs.hpp"


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

private:
    Qt3DCore::QEntity * entity_;
    Qt3DCore::QTransform * transform_;
    int dt_ = UPDATE_INTERVAL;
};

