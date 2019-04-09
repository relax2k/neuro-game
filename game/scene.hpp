#ifndef SCENE_HPP
#define SCENE_HPP

#include "stdafx.hpp"


class Scene {
public:
    explicit Scene(Qt3DCore::QEntity * root);

private:
    Qt3DCore::QEntity * rootEntity_;
    Qt3DCore::QEntity * table_;
    Qt3DCore::QEntity * thorus_;
};

#endif // SCENE_HPP
