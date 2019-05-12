#pragma once

#include "stdafx.hpp"

#define ASSETS "qrc:/assets/"


class Scene {
public:
    explicit Scene(Qt3DCore::QEntity * root);

private:
    Qt3DCore::QEntity * createTable()               const;
    Qt3DCore::QEntity * createRoom()                const;
    Qt3DCore::QEntity * createCarpet()              const;
    QVector<Qt3DCore::QEntity *> createLights()     const;
    Qt3DCore::QEntity * createLight(QVector3D pos)  const;
    Qt3DCore::QEntity * createCeiling()             const;
    Qt3DCore::QEntity * createGrid()                const;
    Qt3DCore::QEntity * createRacket(float const x,
                                     float const y,
                                     float const z) const;
    Qt3DCore::QEntity * createBall(float const x,
                                   float const y,
                                   float const z)   const;

private:
    Qt3DCore::QEntity * rootEntity_;
    Qt3DCore::QEntity * table_;
    Qt3DCore::QEntity * room_;
    Qt3DCore::QEntity * carpet_;
    Qt3DCore::QEntity * ceiling_;
    Qt3DCore::QEntity * grid_;
    Qt3DCore::QEntity * racket1_;
    Qt3DCore::QEntity * racket2_;
    Qt3DCore::QEntity * ball_;
    QVector<Qt3DCore::QEntity *> light_;

    constexpr static const float SCALE = 0.005f;
};
