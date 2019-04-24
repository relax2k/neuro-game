#ifndef MAINMENUCONTROLLER_HPP
#define MAINMENUCONTROLLER_HPP

#include "stdafx.hpp"

class MainMenuController : public QObject
{
    Q_OBJECT
public:
    explicit MainMenuController(QObject *parent = nullptr);

signals:

public slots:
    void singlePlayrButtClickd();
    void multiPlayrButtClickd();
    Q_INVOKABLE void settngsButtClickd();
};

#endif // MAINMENUCONTROLLER_HPP
