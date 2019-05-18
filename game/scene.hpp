#pragma once

#include "stdafx.hpp"
#include "table.hpp"

#define ASSETS "qrc:/assets/"


class Ball;

class Scene final {
public:
    explicit Scene(Qt3DCore::QEntity * root);

    Table const * table() const;

private:
    Qt3DCore::QEntity * createRoom()   const;
    Qt3DCore::QEntity * createCarpet() const;
    QVector<Qt3DCore::QEntity *> createLights() const;
    Qt3DCore::QEntity * createLight(QVector3D pos) const;
    Qt3DCore::QEntity * createCeiling() const;

private:
    Qt3DCore::QEntity * rootEntity_;
    Qt3DCore::QEntity * room_;
    Qt3DCore::QEntity * carpet_;
//    Qt3DCore::QEntity * ceiling_; // TODO change scale for sceiling model
    std::unique_ptr<Table> table_;
    QVector<Qt3DCore::QEntity *> light_;
};
