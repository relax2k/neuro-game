#ifndef SCENE_HPP
#define SCENE_HPP

#include "stdafx.hpp"


class Scene {
public:
    explicit Scene(Qt3DCore::QEntity * root);

private:
    Qt3DCore::QEntity * createTable() const;
    Qt3DCore::QEntity * createBox()   const;

private:
    Qt3DCore::QEntity * rootEntity_;
    Qt3DCore::QEntity * table_;
    Qt3DCore::QEntity * thorus_;
    Qt3DCore::QEntity * box_;
};

#endif // SCENE_HPP
