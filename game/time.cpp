#include "time.hpp"


void Clock::init()
{
    // Just to init static variable in instance()
    instance();
}


Clock & Clock::instance()
{
    static Clock inst;
    return inst;
}


Time Clock::time() const
{
    return time_;
}


Clock::Clock()
{
    startTimer(dt_);
}


void Clock::timerEvent(QTimerEvent * event)
{
    Q_UNUSED(event)

    time_ += dt_;

    assert(time_ % dt120_ == 0);
    emit fps120dt(dt120_);
    emit fps120time(time_);

    if (time_ % dt60_ == 0) {
        emit fps60dt(dt60_);
        emit fps60time(time_);
    }

    if (time_ % dt30_ == 0) {
        emit fps30dt(dt30_);
        emit fps30time(time_);
    }
}
