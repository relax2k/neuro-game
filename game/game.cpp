#include "game.hpp"


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

//    auto * camController = new Qt3DExtras::QFirstPersonCameraController(root);
//    camController->setCamera(camera_);
}


void Game::gotoMainMenu()
{
    camera_->setPosition({20, 8, 0});
    camera_->setViewCenter({0, 3, 0});
    camera_->setUpVector({0, 1, 0});
    camFly_ = std::make_unique<CamFlyingAround>(camera_, 20);
}


void Game::singlePlayer()
{
    qDebug() << "Singleplayer";
    setScore({0, 0});
}


void Game::multiplayer()
{
    qDebug() << "Multiplayer";
}


void Game::delCamFly()
{
    if (camFly_) {
        delete camFly_.release();
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















