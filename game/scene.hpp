#pragma once

#include "stdafx.hpp"

#define ASSETS "qrc:/assets/"


class Scene {
public:
    explicit Scene(Qt3DCore::QEntity * root);

private:
    Qt3DCore::QEntity * createTable()  const;
    Qt3DCore::QEntity * createRoom()   const;
    Qt3DCore::QEntity * createCarpet() const;
    Qt3DCore::QEntity * createWall()   const;
    QVector<Qt3DCore::QEntity *> createLight() const;

private:
    Qt3DCore::QEntity * rootEntity_;
    Qt3DCore::QEntity * table_;
    Qt3DCore::QEntity * room_;
    Qt3DCore::QEntity * carpet_;
    Qt3DCore::QEntity * wall_;
    QVector<Qt3DCore::QEntity *> light_;
};
