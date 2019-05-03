#include "stdafx.hpp"

#include "game.hpp"
#include "systems/move/moveaspect.hpp"
#include "mainmenucontroller.hpp"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    Qt3DExtras::Qt3DWindow * view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x2D9EB5)));

    Qt3DCore::QEntity * rootEntity = new Qt3DCore::QEntity();
    view->setRootEntity(rootEntity);

    QWidget * container = QWidget::createWindowContainer(view);
    QSize screenSize = view->screen()->size();
    container->setMinimumSize(QSize(200, 100));
    container->setMaximumSize(screenSize);

    // QML menu init
    QQuickWidget * menuView = new QQuickWidget;            

    menuView->setMaximumSize(QSize(screenSize.width() / 6, screenSize.height()));
    //if You like to replace 6, You should also replace some constants at main.qml
    menuView->setMinimumSize(QSize(200, 100));
    menuView->setSource(QUrl("qrc:/main.qml"));
    //QObject::connect(menuView->engine(), &QQmlEngine::quit,
    //                 &app, &QGuiApplication::quit);

    //create controller to link qml buttons with c++ code
    MainMenuController * menuController = new MainMenuController();

    qmlRegisterSingletonType<Game>("Engine.Core", 1, 0, "Engine",
                                   [](QQmlEngine * engine,
                                      QJSEngine  * scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)
        return Game::instance();
    });      

    //link controller to qml
    menuView->rootContext()->setContextProperty("cppController", menuController);

    //link quit button to quit
    QObject::connect(menuView->engine(), SIGNAL(quit()), QCoreApplication::instance(), SLOT(quit()));
    // end QML menu init


    QWidget * widget = new QWidget;
    QHBoxLayout * hLayout = new QHBoxLayout(widget);

    //This order is so important, don't touch it!
    hLayout->addWidget(container); // right column
    hLayout->addWidget(menuView);  // left column


    view->registerAspect(new MoveAspect);


    Game::instance()->init(rootEntity, view->camera());

    widget->setWindowTitle(QStringLiteral("Brain tennis"));
    widget->show();
    widget->resize(1280, 768);

    return QGuiApplication::exec();
}
