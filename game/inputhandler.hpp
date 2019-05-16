#pragma once

#include "stdafx.hpp"


class InputHandler final
        : public Qt3DCore::QEntity {
    Q_OBJECT

public:
    explicit InputHandler(Qt3DCore::QEntity * parent = nullptr);

signals:
    void spacePressed();

private slots:
    void keyboardEvent(Qt3DInput::QKeyEvent * event);

private:
    Qt3DInput::QKeyboardDevice  * keyController_;
    Qt3DInput::QInputSettings   * inputSettings_;
    Qt3DInput::QKeyboardHandler * keyHandler_;
};


