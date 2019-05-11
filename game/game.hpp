#pragma once

#include "stdafx.hpp"
#include "scene.hpp"
#include "camflyingaround.hpp"


class Game
        : public QObject {
    Q_OBJECT

public:
    using Score = std::pair<int, int>;

    explicit Game(Qt3DCore::QEntity * root,
                  Qt3DRender::QCamera * camera, QObject * parent = nullptr);

    void addScore(Score delta);
    void setScore(Score val);
    Score score() const;

public slots:
    Q_INVOKABLE void gotoMainMenu();
    Q_INVOKABLE void singlePlayer();
    Q_INVOKABLE void multiplayer();

    // Attempts to access cpp struct from qml failed
    Q_INVOKABLE int score1() const;
    Q_INVOKABLE int score2() const;

signals:
    void scoreChanged(Score newScore);

private:
    void delCamFly();

private:
    Score score_{};

    Qt3DCore::QEntity    * rootEntity_;
    Qt3DRender::QCamera  * camera_;
    std::unique_ptr<Scene> scene_;

    std::unique_ptr<CamFlyingAround> camFly_;
};
