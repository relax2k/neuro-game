#include "scene.hpp"


Scene::Scene(Qt3DCore::QEntity * root)
    : rootEntity_(root)
    , table_     (createTable())
    , room_      (createRoom())
    , carpet_    (createCarpet())
    , ceiling_   (createCeiling())
    , grid_      (createGrid())
    , light_     (createLights())
{
    assert(rootEntity_);
}


Qt3DCore::QEntity * Scene::createTable() const
{
    auto * transform = new Qt3DCore::QTransform;
    transform->setTranslation({0, 0, 0});
    transform->setScale(SCALE);
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
    transform->setScale(SCALE);
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


Qt3DCore::QEntity * Scene::createCeiling() const
{
    auto * transform = new Qt3DCore::QTransform;
    transform->setTranslation({0, 0, 0});
    transform->setScale(SCALE);
    transform->setRotation(
                QQuaternion::fromAxisAndAngle(QVector3D(0, 1, 0), 90));

    auto * mesh = new Qt3DRender::QMesh;
    mesh->setSource({ASSETS "ceiling.obj"});

    auto * textureLoader = new Qt3DRender::QTextureLoader;
    textureLoader->setSource({ASSETS "ceiling.png"});
    auto * textures = new Qt3DExtras::QDiffuseMapMaterial;
    textures->setDiffuse(textureLoader);

    auto * ceiling = new Qt3DCore::QEntity(rootEntity_);
    ceiling->addComponent(transform);
    ceiling->addComponent(mesh);
    ceiling->addComponent(textures);

    return ceiling;
}



Qt3DCore::QEntity * Scene::createCarpet() const
{
    auto * transform = new Qt3DCore::QTransform;
    transform->setTranslation({0, 0, 0});
    transform->setScale(SCALE);
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


Qt3DCore::QEntity * Scene::createGrid() const
{
    auto * transform = new Qt3DCore::QTransform;
    transform->setTranslation({0, 0, 0});
    transform->setScale(SCALE);
    transform->setRotation(
                QQuaternion::fromAxisAndAngle(QVector3D(0, 1, 0), 90));

    auto * mesh = new Qt3DRender::QMesh;
    mesh->setSource({ASSETS "grid.obj"});

    auto * textureLoader = new Qt3DRender::QTextureLoader;
    textureLoader->setSource({ASSETS "grid.png"});
    //textureLoader->setFormat(Qt3DRender::QAbstractTexture::RGBA16F);
    auto * textures = new Qt3DExtras::QDiffuseMapMaterial;
    textures->setDiffuse(textureLoader);
    textures->setSpecular({0, 0, 0});

    auto * grid = new Qt3DCore::QEntity(rootEntity_);
    grid->addComponent(transform);
    grid->addComponent(mesh);
    grid->addComponent(textures);

    return grid;

}


QVector<Qt3DCore::QEntity *> Scene::createLights() const
{
    auto * light1 = createLight({10, 10, 3});
    auto * light2 = createLight({10, -10, 3});
    auto * light3 = createLight({-10, -10, 3});
    auto * light4 = createLight({-10, 10, 3});


    return { light1, light2, light3, light4};
}


Qt3DCore::QEntity * Scene::createLight(QVector3D pos) const
{
    auto * transform = new Qt3DCore::QTransform;
    transform->setTranslation(pos);

    Qt3DRender::QPointLight * light = new Qt3DRender::QPointLight;
    light->setIntensity(0.4f);

    Qt3DCore::QEntity * lightEntity = new Qt3DCore::QEntity(rootEntity_);
    lightEntity->addComponent(light);
    lightEntity->addComponent(transform);

    return lightEntity;
}











