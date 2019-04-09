#include "scene.hpp"


Scene::Scene(Qt3DCore::QEntity * root)
    : rootEntity_(root)
    , table_     (new Qt3DCore::QEntity(root))
    , thorus_    (new Qt3DCore::QEntity(root))
{
    Qt3DCore::QTransform * torusTransform = new Qt3DCore::QTransform();
    torusTransform->setScale(2.0f);
    torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 25.0f));
    torusTransform->setTranslation(QVector3D(0,0,0));

    Qt3DExtras::QPhongMaterial * torusMaterial = new Qt3DExtras::QPhongMaterial();
    torusMaterial->setDiffuse(QColor(QRgb(0xbeb32b)));

    auto mesh = new Qt3DExtras::QTorusMesh;

    thorus_->addComponent(mesh);
    thorus_->addComponent(torusMaterial);
    thorus_->addComponent(torusTransform);
}
