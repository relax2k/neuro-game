#pragma once

#include "stdafx.hpp"
#include "scene.hpp"
#include "camflyingaround.hpp"


class Game
        : public QObject {
    Q_OBJECT

public:
    explicit Game(Qt3DCore::QEntity * root,
                  Qt3DRender::QCamera * camera, QObject * parent = nullptr);
    void init(Qt3DCore::QEntity * rootEntity, Qt3DRender::QCamera * camera);

public slots:
    Q_INVOKABLE void gotoMainMenu();
    Q_INVOKABLE void singlePlayer();
    Q_INVOKABLE void multiplayer();

private:
    void delCamFly();

private:
    Qt3DCore::QEntity    * rootEntity_;
    Qt3DRender::QCamera  * camera_;
    std::unique_ptr<Scene> scene_;

    std::unique_ptr<CamFlyingAround> camFly_;
};
