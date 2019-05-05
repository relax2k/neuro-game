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

    // TODO(cam pos)
    camera_->setPosition({20, 2, 0});
    camera_->setViewCenter({0, 0, 0});
    camera_->setUpVector({0, 1, 0});

    auto * camController = new Qt3DExtras::QFirstPersonCameraController(root);
    camController->setCamera(camera_);
}


void Game::singlePlayer()
{
    qDebug() << "Singleplayer";
}


void Game::multiplayer()
{
    qDebug() << "Multiplayer";
}
