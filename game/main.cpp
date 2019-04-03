#include <QGuiApplication>
#include <QtGui/QOpenGLContext>
#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickView>

#include "ball.hpp"
#include "engine.hpp"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QSurfaceFormat format;
    if (QOpenGLContext::openGLModuleType() == QOpenGLContext::LibGL) {
        format.setVersion(3, 2);
        format.setProfile(QSurfaceFormat::CoreProfile);
    }
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);

    qmlRegisterType<Ball>("Engine.Objs", 1, 0, "CBall");
    qmlRegisterSingletonType<Engine>("Engine.Core", 1, 0, "Engine",
                                     [](QQmlEngine * /*engine*/,
                                     QJSEngine * /*scriptEngine*/) -> QObject * {
        auto * engine = new Engine();
        return engine;
    });

    QQuickView view;
    view.setFormat(format);
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    QObject::connect(view.engine(), &QQmlEngine::quit,
                     &app, &QGuiApplication::quit);
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();

    return QGuiApplication::exec();
}
