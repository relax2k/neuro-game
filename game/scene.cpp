#include "scene.hpp"


Scene::Scene(Qt3DCore::QEntity * root)
    : rootEntity_(root)
    , table_     (createTable())
    , room_      (createRoom())
    , carpet_    (createCarpet())
    , wall_      (createWall())
    , light_     (createLights())
{
    assert(rootEntity_);
}


Qt3DCore::QEntity * Scene::createTable() const
{
    auto * transform = new Qt3DCore::QTransform;
    transform->setTranslation({0, 0, 0});
    transform->setScale(1.3f * SCALE);
    transform->setRotation(
                QQuaternion::fromAxisAndAngle(QVector3D(0, 1, 0), 90));

    auto * mesh = new Qt3DRender::QMesh;
    mesh->setSource({ASSETS "table.obj"});

    auto * textureLoader = new Qt3DRender::QTextureLoader;
    textureLoader->setSource({ASSETS "table.png"});
    auto * textures = new Qt3DExtras::QDiffuseMapMaterial;
    textures->setDiffuse(textureLoader);
    textures->setSpecular({0, 0, 0});
    textures->setAmbient({100, 100, 100});

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
    transform->setScale(0.05f * SCALE);
    transform->setRotation(
                QQuaternion::fromAxisAndAngle(QVector3D(0, 1, 0), 90));

    auto * mesh = new Qt3DRender::QMesh;
    mesh->setSource({ASSETS "room.obj"});

    auto * textureLoader = new Qt3DRender::QTextureLoader;
    textureLoader->setSource({ASSETS "room.png"});
    auto * textures = new Qt3DExtras::QDiffuseMapMaterial;
    textures->setDiffuse(textureLoader);
    textures->setSpecular({0,0,0});

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
    transform->setScale(0.05f * SCALE);
    transform->setRotation(
                QQuaternion::fromAxisAndAngle(QVector3D(0, 1, 0), 90));

    auto * mesh = new Qt3DRender::QMesh;
    mesh->setSource({ASSETS "carpet.obj"});

    auto * textureLoader = new Qt3DRender::QTextureLoader;
    textureLoader->setSource({ASSETS "carpet.png"});
    auto * textures = new Qt3DExtras::QDiffuseMapMaterial;
    textures->setDiffuse(textureLoader);
    textures->setSpecular({0, 0, 0});

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
    transform->setScale(0.05f * SCALE);
    transform->setRotation(
                QQuaternion::fromAxisAndAngle(QVector3D(0, 1, 0), 90));

    auto * mesh = new Qt3DRender::QMesh;
    mesh->setSource({ASSETS "walls.obj"});

    auto * textureLoader = new Qt3DRender::QTextureLoader;
    textureLoader->setSource({ASSETS "walls.png"});
    auto * textures = new Qt3DExtras::QDiffuseMapMaterial;
    textures->setDiffuse(textureLoader);

    auto * wall = new Qt3DCore::QEntity(rootEntity_);
    wall->addComponent(transform);
    wall->addComponent(mesh);
    wall->addComponent(textures);

    return wall;
}


QVector<Qt3DCore::QEntity *> Scene::createLights() const
{
    auto * light1 = createLight({10, 10, 10});
    auto * light2 = createLight({-10, 10, -10});
    auto * light3 = createLight({-3, 3, 3});

    return { light1, light2, light3 };
}


Qt3DCore::QEntity * Scene::createLight(QVector3D pos) const
{
    auto * transform = new Qt3DCore::QTransform;
    transform->setTranslation(pos);

    Qt3DRender::QPointLight * light = new Qt3DRender::QPointLight;
    light->setIntensity(0.5f);

    Qt3DCore::QEntity * lightEntity = new Qt3DCore::QEntity(rootEntity_);
    lightEntity->addComponent(light);
    lightEntity->addComponent(transform);

    return lightEntity;
}











