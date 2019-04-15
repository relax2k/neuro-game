#pragma once


#include <cassert>
#include <memory>


#include <QGuiApplication>

#include <QVector3D>
#include <QHash>
#include <QSharedPointer>

#include <QTextureMaterial>
#include <QNormalDiffuseSpecularMapMaterial>
#include <QDiffuseMapMaterial>

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtGui/QScreen>
#include <QQuickView>
#include <QQuickWidget>
#include <QtGui/QOpenGLContext>
#include <QtQml/QQmlEngine>
#include <QStackedLayout>

#include <Qt3DInput/QInputAspect>

#include <Qt3DRender/qcamera.h>
#include <Qt3DRender/qcameralens.h>
#include <Qt3DRender/qmesh.h>
#include <Qt3DRender/qtechnique.h>
#include <Qt3DRender/qmaterial.h>
#include <Qt3DRender/qeffect.h>
#include <Qt3DRender/qtexture.h>
#include <Qt3DRender/qrenderpass.h>
#include <Qt3DRender/qsceneloader.h>
#include <Qt3DRender/qpointlight.h>
#include <Qt3DRender/qrenderaspect.h>
#include <Qt3DRender/QMesh>

#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>
#include <Qt3DCore/qaspectengine.h>
#include <Qt3DCore/QAbstractAspect>
#include <Qt3DCore/QBackendNode>
#include <Qt3DCore/QAspectJob>

#include <Qt3DExtras/qforwardrenderer.h>
#include <Qt3DExtras/qt3dwindow.h>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>
#include <Qt3DExtras/qtorusmesh.h>

#include <Qt3DExtras/QTorusMesh>
#include <Qt3DExtras/QConeMesh>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DExtras/QPlaneMesh>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QPhongMaterial>
