#ifndef PLAYMENUSCORES_HPP
#define PLAYMENUSCORES_HPP

#include "stdafx.hpp"

class PlayMenuScores : public QObject
{
    Q_OBJECT
public:
    //constructor
    PlayMenuScores(int val) : score(val) {}

    //set/get
    int getScore();
    void addScore(int val);
    void setScore(int val);
signals:
    void scSet();
public slots:
    void setScoreSlot(int val);
    int getRequest();
private:
    int score;
};

#endif // PLAYMENUSCORES_HPP
