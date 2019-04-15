#pragma once

#include <stdafx.hpp>


class Movable
        : public Qt3DCore::QComponent
{
    Q_OBJECT

public:
    explicit Movable(Qt3DCore::QNode * parent = nullptr);
};
