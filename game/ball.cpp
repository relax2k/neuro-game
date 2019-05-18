#include "ball.hpp"

#include "scene.hpp"


Ball::Ball(Qt3DCore::QEntity * parent)
    : entity_   (new Qt3DCore::QEntity(parent))
    , transform_(new Qt3DCore::QTransform)
    , xint_     (std::nullopt)
{
    assert(parent);

    auto mesh = new Qt3DRender::QMesh;
    mesh->setSource({ASSETS "ball.obj"});

    auto * textureLoader = new Qt3DRender::QTextureLoader;
    textureLoader->setSource({ASSETS "ball.png"});

    auto * textures = new Qt3DExtras::QDiffuseMapMaterial;
    textures->setDiffuse(textureLoader);
    textures->setSpecular({0, 0, 0});
    textures->setAmbient({100, 100, 100});

    assert(transform_);
    setPos({1, 5, 1});

    assert(entity_);
    entity_->addComponent(mesh);
    entity_->addComponent(textures);
    entity_->addComponent(transform_);

    connect(Clock::instance(), &Clock::fps60dt, this, &Ball::update);
    assert(dt_ == Clock::dt60);

    inInterval_ = isInInterval();
}


Ball::~Ball()
{
    delete entity_;
}


void Ball::setV(QVector3D v)
{
    v_ = v;
}


void Ball::setV(QVector3D newPos, Time dt)
{
    assert(timeToSec(dt) > 0);

    auto dts = timeToSec(dt);

    if (gravity_) {
        v_ = (newPos - pos()) / dts - g_ * dts / 2;
        qDebug() << "v = " << v_;
    } else {
        v_ = (newPos - pos()) / dts;
        qDebug() << "v = " << v_;
    }
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


QVector3D Ball::predictPos(Time dt)
{
    auto dts = timeToSec(dt);
    if (gravity_) {
        return pos() + v_ * dts + g_ * dts * dts / 2;
    }
    return pos() + v_ * dts;
}


float Ball::radius() const
{
    return radius_;
}


Time Ball::dt() const
{
    return dt_;
}


void Ball::reflect(QVector3D n)
{
    assert(!n.isNull());
    v_ = v_ - 2 * (v_ * n) * n;
    emit reflected(v_);
}


void Ball::setBorderCrossNotifier(Interval l)
{
    if (l) {
        if (l->first > l->second) {
            std::swap(l->first, l->second);
        }
    }
    xint_ = l;
}


void Ball::applyGravity()
{
    assert(gravity_);
    v_ += g_ * timeToSec(dt_);
}


void Ball::move()
{
    transform_->setTranslation(pos() + timeToSec(dt_) * v_);
}


bool Ball::isInInterval() const
{
    assert([this] {
        if (xint_) {
            return xint_->first <= xint_->second;
        }
        return true;
    } ());

    if (!xint_) {
        return false;
    }

    if (qreal(pos().x()) < xint_->first || xint_->second < qreal(pos().x())) {
        return false;
    }
    return true;
}


void Ball::update(Time dt)
{
    assert(dt == dt_);

    if (gravity_) {
        applyGravity();
    }

    move();

    const bool wasInInterval = inInterval_;
    inInterval_ = isInInterval();
    if (wasInInterval && !inInterval_) {
        emit borderCrossed(false);
        qDebug() << "Crossed out";
    }
    if (!wasInInterval && inInterval_) {
        emit borderCrossed(true);
        qDebug() << "Crossed into";
    }
}












