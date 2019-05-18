#pragma once

#include "stdafx.hpp"


class Ball;

class Table final
        : public QObject {
    Q_OBJECT

public:
    explicit Table(Qt3DCore::QEntity * parent);

    std::optional<QVector3D> intersects(Ball const * ball) const;

public:
    static constexpr float x1 = -6.86f;
    static constexpr float x2 = -x1;
    static constexpr float h  = 3.86f;
    static constexpr float z1 = -3.81f;
    static constexpr float z2 = -z1;

    static constexpr float gridY1 = 1.0f;
    static constexpr float gridY2 = 4.72f;
    static constexpr float gridZ1 = -4.5f;
    static constexpr float gridZ2 = -gridZ1;

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
