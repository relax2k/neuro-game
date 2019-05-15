#include "inputhandler.hpp"


InputHandler::InputHandler(Qt3DCore::QEntity * parent)
    : Qt3DCore::QEntity(parent)
    , keyController_(new Qt3DInput::QKeyboardDevice (parent))
    , inputSettings_(new Qt3DInput::QInputSettings  (parent))
    , keyHandler_   (new Qt3DInput::QKeyboardHandler(parent))
{
    assert(parent);
    assert(keyController_);
    assert(keyHandler_);

    keyHandler_->setSourceDevice(keyController_);
    keyHandler_->setFocus(true);
    addComponent(keyHandler_);

    parent->addComponent(keyHandler_);

    connect(keyHandler_, &Qt3DInput::QKeyboardHandler::pressed,
            this, &InputHandler::keyboardEvent);
}


void InputHandler::keyboardEvent(Qt3DInput::QKeyEvent * event)
{
    qDebug() << "keyboardEvent!";
    if (event->key() == Qt::Key_Space) {
        emit spacePressed();
    }
}
