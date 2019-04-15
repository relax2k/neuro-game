#pragma once

#include "stdafx.hpp"


class Scene {
public:
    explicit Scene(Qt3DCore::QEntity * root);

private:
    Qt3DCore::QEntity * createTable() const;
    Qt3DCore::QEntity * createBox()   const;
    Qt3DCore::QEntity * createRoom()  const;

private:
    Qt3DCore::QEntity * rootEntity_;
    Qt3DCore::QEntity * table_;
    Qt3DCore::QEntity * box_;
    Qt3DCore::QEntity * room_;
};
