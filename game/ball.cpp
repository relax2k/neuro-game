#include "ball.hpp"

#include "scene.hpp"


Ball::Ball(Qt3DCore::QEntity * parent, int dt)
    : entity_   (new Qt3DCore::QEntity(parent))
    , transform_(new Qt3DCore::QTransform)
    , dt_(dt)
{
    assert(parent);
    assert(dt > 0);

    auto mesh = new Qt3DRender::QMesh;
    mesh->setSource({ASSETS "ball.obj"});

    auto * textureLoader = new Qt3DRender::QTextureLoader;
    textureLoader->setSource({ASSETS "ball.png"});

    auto * textures = new Qt3DExtras::QDiffuseMapMaterial;
    textures->setDiffuse(textureLoader);
    textures->setSpecular({0, 0, 0});
    textures->setAmbient({100, 100, 100});

    assert(transform_);
    transform_->setScale(Scene::SCALE);
    setPos({1, 5, 1});

    assert(entity_);
    entity_->addComponent(mesh);
    entity_->addComponent(textures);
    entity_->addComponent(transform_);

    startTimer(dt);
}


Ball::~Ball()
{
    delete entity_;
}


void Ball::setV(QVector3D v)
{
    v_ = v;
}


QVector3D Ball::v() const
{
    return v_;
}


void Ball::setGravity(bool b)
{
    gravity_ = b;
}


bool Ball::gravity() const
{
    return gravity_;
}


void Ball::setPos(QVector3D pos)
{
    assert(transform_);
    transform_->setTranslation(pos);
}


QVector3D Ball::pos() const
{
    return transform_->translation();
}


void Ball::timerEvent(QTimerEvent * event)
{
    Q_UNUSED(event)

    if (gravity_) {
        applyGravity();
    }
    move();
}


void Ball::applyGravity()
{
    assert(gravity_);
    // TODO
}


void Ball::move()
{
    // TODO
}







