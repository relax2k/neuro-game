#pragma once

#include "stdafx.hpp"

#define ASSETS "qrc:/assets/"


class Ball;

class Scene final {
public:
    explicit Scene(Qt3DCore::QEntity * root);

    std::pair<QVector3D, bool> intersectsWithTable(Ball const * ball) const;
    std::pair<QVector3D, bool> intersectsWithGrid (Ball const * ball) const;

public:
    constexpr static const float SCALE = 0.005f;

private:
    bool inTable(QVector3D pos) const;

    Qt3DCore::QEntity * createTable()  const;
    Qt3DCore::QEntity * createRoom()   const;
    Qt3DCore::QEntity * createCarpet() const;
    QVector<Qt3DCore::QEntity *> createLights() const;
    Qt3DCore::QEntity * createLight(QVector3D pos) const;
    Qt3DCore::QEntity * createCeiling() const;
    Qt3DCore::QEntity * createGrid() const;

private:
    Qt3DCore::QEntity * rootEntity_;
    Qt3DCore::QEntity * table_;
    Qt3DCore::QEntity * room_;
    Qt3DCore::QEntity * carpet_;
    Qt3DCore::QEntity * ceiling_;
    Qt3DCore::QEntity * grid_;
    QVector<Qt3DCore::QEntity *> light_;
};
