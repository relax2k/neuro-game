#include "stdafx.hpp"

#include "game.hpp"
#include "systems/move/moveaspect.hpp"

#include "engine.hpp"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    Qt3DExtras::Qt3DWindow * view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x2D9EB5)));

    Qt3DCore::QEntity * rootEntity = new Qt3DCore::QEntity();
    view->setRootEntity(rootEntity);

    //QML menu init

    qmlRegisterSingletonType<Engine>("Engine.Core", 1, 0, "Engine",
                                     [](QQmlEngine *,
                                     QJSEngine *) -> QObject * {
        auto * engine = new Engine();
        return engine;
    });

    QQuickWidget * menuView = new QQuickWidget;
    menuView->setSource(QUrl("qrc:/main.qml"));
    QObject::connect(menuView->engine(), &QQmlEngine::quit,
                     &app, &QGuiApplication::quit);

    //end QML menu init

    QWidget * container = QWidget::createWindowContainer(view);
    QSize screenSize = view->screen()->size();
    container->setMinimumSize(QSize(200, 100));
    //container->setMaximumSize(screenSize);
    container->setMaximumSize(QSize(500, 500));

    QWidget * widget = new QWidget;
    QStackedLayout * stackedLayout = new QStackedLayout(widget);

    stackedLayout->setStackingMode(QStackedLayout::StackAll);
    stackedLayout->addWidget(menuView);
    stackedLayout->addWidget(container);
    stackedLayout->setCurrentWidget(menuView);

    view->registerAspect(new MoveAspect);

    Game::instance().init(rootEntity, view->camera());

    widget->setWindowTitle(QStringLiteral("Brain tennis"));
    widget->show();
    widget->resize(1200, 800);

    return QGuiApplication::exec();
}
