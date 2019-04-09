#include "stdafx.hpp"

#include "game.hpp"


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

    QWidget * widget = new QWidget;
    QHBoxLayout * hLayout = new QHBoxLayout(widget);
    hLayout->addWidget(container);

//    view->registerAspect(new CustomAspect);


    Game::instance().init(rootEntity, view->camera());

    widget->setWindowTitle(QStringLiteral("Brain tennis"));
    widget->show();
    widget->resize(1200, 800);

    return app.exec();
}
