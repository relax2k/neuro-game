#pragma once

#include "stdafx.hpp"


using Time = int64_t;

class Clock final
        : public QObject {
    Q_OBJECT

public:
    static void init();
    static Clock * instance();

    /**
     * @brief Slows down timer.
     * @param percent of default frequency.
     */
    void setDeceleration(int percent);
    int deceleration() const;

    Time time() const;

    using Timer = void (Clock::*) (Time);
    Timer getTimerSignalDt(Time dt);

public:
    // Number is fps
    static const Time dt120 = 8;
    static const Time dt60  = 16;
    static const Time dt30  = 32;
    static const Time dt = dt120;

signals:
    void fps120dt  (Time dt);
    void fps120time(Time time);

    void fps60dt  (Time dt);
    void fps60time(Time time);

    void fps30dt  (Time dt);
    void fps30time(Time time);

private:
    Clock();
    bool skipTimerEvent() const;
    void timerEvent(QTimerEvent * event) override;

private:
    Time absoluteTime_ = 0;
    Time time_ = 0;
    int signalsInHundredTicks_ = 100;
};

