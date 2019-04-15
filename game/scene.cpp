#include "scene.hpp"


Scene::Scene(Qt3DCore::QEntity * root)
    : rootEntity_(root)
    , table_     (createTable())
    , box_       (createBox())
    , room_      (createRoom())
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


Qt3DCore::QEntity * Scene::createBox() const
{
    auto * mesh = new Qt3DRender::QMesh;
    mesh->setSource({"qrc:/models/box.obj"});

    auto * transform = new Qt3DCore::QTransform;
    transform->setTranslation({-10, 0, -10});
    transform->setScale(0.1f);
    transform->setRotation(
                QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90.0f));

    auto * textureLoader = new Qt3DRender::QTextureLoader;
    textureLoader->setSource({"qrc:/models/box.png"});
    auto * textures = new Qt3DExtras::QDiffuseMapMaterial;
    textures->setDiffuse(textureLoader);

    auto box = new Qt3DCore::QEntity(rootEntity_);
    box->addComponent(textures);
    box->addComponent(mesh);
    box->addComponent(transform);

    return box;
}


Qt3DCore::QEntity * Scene::createRoom() const
{
    auto * transform = new Qt3DCore::QTransform;
    transform->setTranslation({0, 0, 0});
    transform->setScale(1);
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






















