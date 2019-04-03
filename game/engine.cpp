#include "engine.hpp"


void Engine::init()
{
    setState(State::MENU);
}


void Engine::update()
{
    // TODO(Yuki/Engine::update())
}


void Engine::setState(State st)
{
    state = st;
    emit stateChanged();
}


Engine::State Engine::getState() const
{
    return state;
}
