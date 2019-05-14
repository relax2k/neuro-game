#pragma once

#include "stdafx.hpp"


using Time = int64_t;

class Clock final
        : public QObject {
    Q_OBJECT

public:
    void init();
    Clock & instance();

    Time time() const;

public:
    // Number is fps
    static const Time dt120_ = 8;
    static const Time dt60_  = 16;
    static const Time dt30_  = 32;
    static const Time dt_ = dt120_;

signals:
    void fps120dt  (Time dt);
    void fps120time(Time time);

    void fps60dt  (Time dt);
    void fps60time(Time time);

    void fps30dt  (Time dt);
    void fps30time(Time time);

private:
    Clock();
    void timerEvent(QTimerEvent * event) override;

private:
    Time time_ = 0;
};

