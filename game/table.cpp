#include "table.hpp"

#include "scene.hpp"
#include "ball.hpp"


Table::Table(Qt3DCore::QEntity * parent)
    : tableEntity_   (new Qt3DCore::QEntity(parent))
    , tableTransform_(new Qt3DCore::QTransform)
    , gridEntity_    (new Qt3DCore::QEntity(parent))
    , gridTransform_ (new Qt3DCore::QTransform)
{
    assert(parent);

    initTable();
    initGrid();
}


void Table::initTable()
{
    assert(tableEntity_);
    assert(tableTransform_);

    tableTransform_->setTranslation({0, 0, 0});
    tableTransform_->setRotation(
                QQuaternion::fromAxisAndAngle(QVector3D(0, 1, 0), 90));

    auto * mesh = new Qt3DRender::QMesh;
    mesh->setSource({ASSETS "table.obj"});

    auto * textureLoader = new Qt3DRender::QTextureLoader;
    textureLoader->setSource({ASSETS "table.png"});
    auto * textures = new Qt3DExtras::QDiffuseMapMaterial;
    textures->setDiffuse(textureLoader);
    textures->setSpecular({0, 0, 0});
    textures->setAmbient({100, 100, 100});

    tableEntity_->addComponent(tableTransform_);
    tableEntity_->addComponent(mesh);
    tableEntity_->addComponent(textures);
}


void Table::initGrid()
{
    assert(gridEntity_);
    assert(gridTransform_);

    gridTransform_->setTranslation({0, 0, 0});
    gridTransform_->setRotation(
                QQuaternion::fromAxisAndAngle(QVector3D(0, 1, 0), 90));

    auto * mesh = new Qt3DRender::QMesh;
    mesh->setSource({ASSETS "grid.obj"});

    auto * textureLoader = new Qt3DRender::QTextureLoader;
    textureLoader->setSource({ASSETS "grid.png"});
    //textureLoader->setFormat(Qt3DRender::QAbstractTexture::RGBA16F);
    auto * textures = new Qt3DExtras::QDiffuseMapMaterial;
    textures->setDiffuse(textureLoader);
    textures->setSpecular({0, 0, 0});

    gridEntity_->addComponent(gridTransform_);
    gridEntity_->addComponent(mesh);
    gridEntity_->addComponent(textures);
}


std::optional<QVector3D> Table::intersects(Ball const * ball) const
{
    if (auto n = intersectsWithTable(ball)) {
        return n;
    }
    if (auto n = intersectsWithGrid(ball)) {
        return n;
    }
    return std::nullopt;
}


std::optional<QVector3D> Table::intersectsWithTable(Ball const * ball) const
{
    if (ball->pos().y() - ball->radius() <= h &&
            inTable(ball->pos())) {
        return { QVector3D(0, 1, 0) };
    } else {
        return std::nullopt;
    }
}


std::optional<QVector3D> Table::intersectsWithGrid(Ball const * ball) const
{
    const auto pos = ball->pos();

    assert(gridTransform_->translation().x() < 1e-5f);

    if (pos.z() <= gridZ2 && pos.z() >= gridZ1 &&
            pos.y() >= gridY2 && pos.y() <= gridY1 &&
            std::abs(pos.x()) <= ball->radius()) {
        if (pos.x() < 0) {
            return { QVector3D(-1, 0, 0) };
        } else {
            return { QVector3D(1, 0, 0) };
        }
    }

    return std::nullopt;
}


bool Table::inTable(QVector3D pos) const
{
    return pos.x() >= x1 && pos.x() <= x2 &&
            pos.z() >= z1 && pos.z() <= z2;
}









