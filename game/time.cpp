#include "time.hpp"


void Clock::init()
{
    // Just to init static variable in instance()
    instance();
}


Clock * Clock::instance()
{
    static Clock inst;
    return &inst;
}


Time Clock::time() const
{
    return time_;
}


Clock::Timer Clock::getTimerSignalDt(Time dt)
{
    switch (dt) {
    case dt120:
        return &Clock::fps120dt;
    case dt60:
        return &Clock::fps60dt;
    case dt30:
        return &Clock::fps30dt;
    default:
        qDebug() << "Clock: no such timer with dt = " << dt;
        return nullptr;
    }
}


Clock::Clock()
{
    startTimer(dt);
}


void Clock::timerEvent(QTimerEvent * event)
{
    Q_UNUSED(event)

    time_ += dt;

    assert(time_ % dt120 == 0);
    emit fps120dt(dt120);
    emit fps120time(time_);

    if (time_ % dt60 == 0) {
        emit fps60dt(dt60);
        emit fps60time(time_);
    }

    if (time_ % dt30 == 0) {
        emit fps30dt(dt30);
        emit fps30time(time_);
    }
}
