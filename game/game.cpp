#include "game.hpp"

#include "ball.hpp"
#include "racket.hpp"


Game::Game(Qt3DCore::QEntity * root,
           Qt3DRender::QCamera * camera, QObject * parent)
    : QObject    (parent)
    , rootEntity_(root)
    , camera_    (camera)
    , scene_     (std::make_unique<Scene>(root))
{
    assert(root);
    assert(camera);

    gotoMainMenu();

    // auto * camController = new Qt3DExtras::QFirstPersonCameraController(root);
    // camController->setCamera(camera_);
}


void Game::gotoMainMenu()
{
    camera_->setPosition({20, 8, 0});
    camera_->setViewCenter({0, 3, 0});
    camera_->setUpVector({0, 1, 0});
    camFly_ = std::make_unique<CamFlyingAround>(camera_, 20);

    delRackets();
    delBall();
}


void Game::singlePlayer()
{
    qDebug() << "Singleplayer";
    setScore({0, 0});

    delCamFly();
    camPlayPos();

    assert(!racket1_ && !racket2_);
    assert(!ball_);

    racket1_ = new Racket(rootEntity_);
    racket1_->setPos({5.0, 5.0, 0.0});
    racket2_ = new Racket(rootEntity_);
    racket2_->setPos({-5.0, 5.0, 0.0});

    ball_ = new Ball(rootEntity_);
}


void Game::multiplayer()
{
    qDebug() << "Multiplayer";
}


void Game::camPlayPos()
{
    camera_->setPosition({20, 8, 0});
    camera_->setViewCenter({0, 3, 0});
    camera_->setUpVector({0, 1, 0});
}


void Game::delCamFly()
{
    if (camFly_) {
        delete camFly_.release();
    }
}


void Game::delRackets()
{
    if (racket1_) {
        delete racket1_;
        racket1_ = nullptr;
    }
    if (racket2_) {
        delete racket2_;
        racket2_ = nullptr;
    }
}


void Game::delBall()
{
    if (ball_) {
        delete ball_;
        ball_ = nullptr;
    }
}


void Game::addScore(Score val)
{
    score_.first  += val.first;
    score_.second += val.second;
    emit scoreChanged(score_);
}


void Game::setScore(Score val)
{
    score_ = val;
    emit scoreChanged(score_);
}


Game::Score Game::score() const
{
    return score_;
}


int Game::score1() const
{
    return score_.first;
}


int Game::score2() const
{
    return score_.second;
}















