#include "scene.hpp"


Scene::Scene(Qt3DCore::QEntity * root)
    : rootEntity_(root)
    , table_     (createTable())
    , room_      (createRoom())
    , carpet_    (createCarpet())
    , wall_      (createWall())
{
    assert(rootEntity_);
}


Qt3DCore::QEntity * Scene::createTable() const
{
    auto * transform = new Qt3DCore::QTransform;
    transform->setTranslation({0, 0, 0});
    transform->setScale(1);
    transform->setRotation(
                QQuaternion::fromAxisAndAngle(QVector3D(0, 1, 0), 90));

    auto * mesh = new Qt3DRender::QMesh;
    mesh->setSource({"qrc:/models/table.obj"});

    auto * textureLoader = new Qt3DRender::QTextureLoader;
    textureLoader->setSource({"qrc:/models/table.png"});
    auto * textures = new Qt3DExtras::QDiffuseMapMaterial;
    textures->setDiffuse(textureLoader);

    auto * table = new Qt3DCore::QEntity(rootEntity_);
    table->addComponent(transform);
    table->addComponent(mesh);
    table->addComponent(textures);

    return table;
}


Qt3DCore::QEntity * Scene::createRoom() const
{
    auto * transform = new Qt3DCore::QTransform;
    transform->setTranslation({0, 0, 0});
    transform->setScale(0.05f);
    transform->setRotation(
                QQuaternion::fromAxisAndAngle(QVector3D(0, 1, 0), 90));

    auto * mesh = new Qt3DRender::QMesh;
    mesh->setSource({"qrc:/models/room.obj"});

    auto * textureLoader = new Qt3DRender::QTextureLoader;
    textureLoader->setSource({"qrc:/models/room.png"});
    auto * textures = new Qt3DExtras::QDiffuseMapMaterial;
    textures->setDiffuse(textureLoader);

    auto * room = new Qt3DCore::QEntity(rootEntity_);
    room->addComponent(transform);
    room->addComponent(mesh);
    room->addComponent(textures);

    return room;
}


Qt3DCore::QEntity * Scene::createCarpet() const
{
    auto * transform = new Qt3DCore::QTransform;
    transform->setTranslation({0, 0, 0});
    transform->setScale(0.05f);
    transform->setRotation(
                QQuaternion::fromAxisAndAngle(QVector3D(0, 1, 0), 90));

    auto * mesh = new Qt3DRender::QMesh;
    mesh->setSource({"qrc:/models/carpet.obj"});

    auto * textureLoader = new Qt3DRender::QTextureLoader;
    textureLoader->setSource({"qrc:/models/carpet.png"});
    auto * textures = new Qt3DExtras::QDiffuseMapMaterial;
    textures->setDiffuse(textureLoader);

    auto * carpet = new Qt3DCore::QEntity(rootEntity_);
    carpet->addComponent(transform);
    carpet->addComponent(mesh);
    carpet->addComponent(textures);

    return carpet;
}


Qt3DCore::QEntity * Scene::createWall() const
{
    auto * transform = new Qt3DCore::QTransform;
    transform->setTranslation({0, 0, 0});
    transform->setScale(0.05f);
    transform->setRotation(
                QQuaternion::fromAxisAndAngle(QVector3D(0, 1, 0), 90));

    auto * mesh = new Qt3DRender::QMesh;
    mesh->setSource({"qrc:/models/walls.obj"});

    auto * textureLoader = new Qt3DRender::QTextureLoader;
    textureLoader->setSource({"qrc:/models/walls.png"});
    auto * textures = new Qt3DExtras::QDiffuseMapMaterial;
    textures->setDiffuse(textureLoader);

    auto * wall = new Qt3DCore::QEntity(rootEntity_);
    wall->addComponent(transform);
    wall->addComponent(mesh);
    wall->addComponent(textures);

    return wall;
}

















