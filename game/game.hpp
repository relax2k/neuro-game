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

    //scores
    void addScore(int val);
    void setScore(int val);
    int getScore();

signals:
    void scoreChanged();
public slots:
    Q_INVOKABLE void gotoMainMenu();
    Q_INVOKABLE void singlePlayer();
    Q_INVOKABLE void multiplayer();

    Q_INVOKABLE int scoreGetRequest();

private:
    void delCamFly();

private:
    int score;
    Qt3DCore::QEntity    * rootEntity_;
    Qt3DRender::QCamera  * camera_;
    std::unique_ptr<Scene> scene_;

    std::unique_ptr<CamFlyingAround> camFly_;
};
