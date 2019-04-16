#pragma once

#include "stdafx.hpp"
#include "scene.hpp"


class Game final {
public:
    static Game & instance();

    void init(Qt3DCore::QEntity * rootEntity, Qt3DRender::QCamera * camera);

private:
    Game() = default;

private:
    Qt3DCore::QEntity   * rootEntity_ = nullptr;
    Qt3DRender::QCamera * camera_     = nullptr;
    std::unique_ptr<Scene> scene_;
};


inline Game & Game::instance() {
    static Game inst;
    return inst;
}
