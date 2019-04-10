#include "scene.hpp"


Scene::Scene(Qt3DCore::QEntity * root)
    : rootEntity_(root)
    , table_     (createTable())
    , thorus_    (new Qt3DCore::QEntity(root))
    , box_       (createBox())
{
    Qt3DCore::QTransform * torusTransform = new Qt3DCore::QTransform();
    torusTransform->setScale(1);
    torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 25.0f));
    torusTransform->setTranslation(QVector3D(0,0,0));

    Qt3DExtras::QPhongMaterial * torusMaterial = new Qt3DExtras::QPhongMaterial();
    torusMaterial->setDiffuse(QColor(QRgb(0xbeb32b)));

    auto mesh = new Qt3DExtras::QTorusMesh;

    thorus_->addComponent(mesh);
    thorus_->addComponent(torusMaterial);
    thorus_->addComponent(torusTransform);
}


Qt3DCore::QEntity * Scene::createTable() const
{
    assert(rootEntity_);

    auto * transform = new Qt3DCore::QTransform;
    transform->setTranslation({-10, -10, -10});
    transform->setScale(0.1f);
    transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0, 0, 1), 50.0f));

    auto * mesh = new Qt3DRender::QMesh;
    mesh->setSource({"qrc:/models/table.obj"});

    auto * material = new Qt3DExtras::QPhongMaterial;
    material->setDiffuse(QColor(QRgb(0xbeb32b)));

    auto * textureLoader = new Qt3DRender::QTextureLoader;
    textureLoader->setSource({"qrc:/models/table.png"});

    auto * textures = new Qt3DExtras::QDiffuseMapMaterial;
    textures->setDiffuse(textureLoader);

    auto * table = new Qt3DCore::QEntity(rootEntity_);
    table->addComponent(transform);
    table->addComponent(mesh);
//    table->addComponent(material);
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
    transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 25.0f));

    auto * material = new Qt3DExtras::QPhongMaterial;
    material->setDiffuse(QColor(QRgb(0xbeb32b)));

    auto * textureLoader = new Qt3DRender::QTextureLoader;
    textureLoader->setSource({"qrc:/models/box.png"});

//    auto * textures = new Qt3DExtras::QNormalDiffuseSpecularMapMaterial;
//    textures->setDiffuse(textureLoader);

    auto * textures = new Qt3DExtras::QDiffuseMapMaterial;
    textures->setDiffuse(textureLoader);

    auto box = new Qt3DCore::QEntity(rootEntity_);
    box->addComponent(textures);
    box->addComponent(mesh);
    box->addComponent(transform);
//    box->addComponent(material);

    return box;
}

























