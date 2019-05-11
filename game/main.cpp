#include "stdafx.hpp"

#include "game.hpp"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    Qt3DExtras::Qt3DWindow * view3d = new Qt3DExtras::Qt3DWindow();
    view3d->defaultFrameGraph()->setClearColor(QColor(QRgb(0x2D9EB5)));

    Qt3DCore::QEntity * rootEntity = new Qt3DCore::QEntity();
    view3d->setRootEntity(rootEntity);

    QWidget * container = QWidget::createWindowContainer(view3d);
    QSize screenSize = view3d->screen()->size();
    container->setMinimumSize(QSize(200, 100));
    container->setMaximumSize(screenSize);


    // QML menu init
    QQuickWidget * menuView = new QQuickWidget;

    // If You like to replace 6, You should also replace some constants at main.qml
    // TODO
    menuView->setMaximumSize(QSize(screenSize.width() / 6, screenSize.height()));
    menuView->setMinimumSize(QSize(200, 100));
    menuView->setSource(QUrl("qrc:/main.qml"));

    //link quit button to quit
    QObject::connect(menuView->engine(), &QQmlEngine::quit,
                     QCoreApplication::instance(), &QCoreApplication::quit);
    // end QML menu init


    QWidget * widget = new QWidget;
    QHBoxLayout * hLayout = new QHBoxLayout(widget);

    // This order is so important, don't touch it!
    hLayout->addWidget(container); // right column
    hLayout->addWidget(menuView);  // left column

    auto game = new Game(rootEntity, view3d->camera());
    menuView->rootContext()->setContextProperty("Game", game);

    widget->setWindowTitle(QStringLiteral("Brain tennis"));
    widget->show();
    widget->resize(1280, 768);

    return QGuiApplication::exec();
}












