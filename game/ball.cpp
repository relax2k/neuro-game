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


int Ball::dt() const
{
    return dt_;
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


float Ball::radius() const
{
    return radius_;
}


void Ball::reflect(QVector3D n)
{
    assert(!n.isNull());
    v_ = v_ - 2 * (v_ * n) * n;
}


void Ball::outOfXIntervalNotifier(Interval l)
{
    if (l.first && l.second) {
        if (l.first > l.second) {
            std::swap(l.first, l.second);
        }
    }
    xint_ = l;
}


void Ball::timerEvent(QTimerEvent * event)
{
    Q_UNUSED(event)

    if (gravity_) {
        applyGravity();
    }
    move();
    if (!isInInterval()) {
        emit outOfXInterval(qreal(pos().x()));
    }
}


void Ball::applyGravity()
{
    assert(gravity_);
    v_ += g_ * toSec(dt_); // To seconds
}


void Ball::move()
{
    transform_->setTranslation(pos() + toSec(dt_) * v_);
}


bool Ball::isInInterval() const
{
    assert([this] {
        if (xint_.first && xint_.second) {
            return xint_.first <= xint_.second;
        }
        return true;
    } ());

    if ((xint_.first && pos().x() < xint_.first) ||
            (xint_.second && xint_.second < pos().x())) {
        return false;
    }
    return true;
}


float Ball::toSec(int t) const
{
    return t / 1000.0f;
}





