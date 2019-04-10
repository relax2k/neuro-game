#include "game.hpp"


void Game::init(Qt3DCore::QEntity * root, Qt3DRender::QCamera * camera)
{
    rootEntity_ = root;
    camera_     = camera;
    scene_      = std::make_unique<Scene>(root);

    // TODO(cam pos)
    camera_->setPosition(QVector3D(20, 20, 0));
    camera_->setViewCenter(QVector3D(0, 0, 0));
}
