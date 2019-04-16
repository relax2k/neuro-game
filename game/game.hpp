#pragma once

#include "stdafx.hpp"
#include "scene.hpp"


class Game
        : public QObject {
    Q_OBJECT

public:
    static Game * instance();

    explicit Game(QObject * parent = nullptr) : QObject(parent) {}
    void init(Qt3DCore::QEntity * rootEntity, Qt3DRender::QCamera * camera);

private:
    virtual ~Game() = default;

private:
    Qt3DCore::QEntity   * rootEntity_ = nullptr;
    Qt3DRender::QCamera * camera_     = nullptr;
    std::unique_ptr<Scene> scene_;
};


inline Game * Game::instance() {
    static Game * inst = new Game;
    return inst;
}
