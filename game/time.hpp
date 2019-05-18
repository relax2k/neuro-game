#pragma once

#include "stdafx.hpp"


using Time = std::chrono::milliseconds;


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
    void setDeceleration(size_t percent);
    size_t deceleration() const;

    Time time() const;

    using Timer = void (Clock::*) (Time);
    Timer getTimerSignalDt(Time dt);

public:
    // Number is fps
    constexpr static Time dt120 = 8ms;
    constexpr static Time dt60  = 16ms;
    constexpr static Time dt30  = 32ms;
    constexpr static Time dt = dt120;

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
    Time absoluteTime_ = 0ms;
    Time time_ = 0ms;
    size_t signalsInHundredTicks_ = 100;
};

