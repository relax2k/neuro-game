#include "playmenuscores.hpp"

int PlayMenuScores::getScore()
{
    return score;
}

void PlayMenuScores::addScore(int val)
{
    score += val;
    emit scSet();
}

void PlayMenuScores::setScore(int val)
{
    score = val;
    emit scSet();
}

int PlayMenuScores::getRequest()
{
    return getScore();
}

void PlayMenuScores::setScoreSlot(int val)
{
    setScore(val);
}
