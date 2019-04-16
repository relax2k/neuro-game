#include "engine.hpp"

void Engine::init()
{
    setState(State::MENU);
    time_ = 0;
    update();
}


void Engine::update()
{
    ++time_;
}


void Engine::setState(State st)
{
    state = st;

    switch (st) {
    case State::GAME:
        gameInit();
        break;

    case State::MENU:
        menuInit();
        break;

    default:
        assert("Undefined game state" && false);
    }

    emit stateChanged();
}


Engine::State Engine::getState() const
{
    return state;
}


void Engine::menuInit() const
{
//    cam_.position() = CAM_MENU_POS_;
}


void Engine::gameInit() const
{
    // TODO(Engine::gameInit)
}
