#pragma once

#include "stdafx.hpp"


class Ball;

class Table final
        : public QObject {
    Q_OBJECT

public:
    explicit Table(Qt3DCore::QEntity * parent);

    std::optional<QVector3D> intersects(Ball const * ball) const;

private:
    void initTable();
    void initGrid();

    std::optional<QVector3D> intersectsWithTable(Ball const * ball) const;
    std::optional<QVector3D> intersectsWithGrid (Ball const * ball) const;
    bool inTable(QVector3D pos) const;

private:
    Qt3DCore::QEntity    * tableEntity_;
    Qt3DCore::QTransform * tableTransform_;
    Qt3DCore::QEntity    * gridEntity_;
    Qt3DCore::QTransform * gridTransform_;
};
