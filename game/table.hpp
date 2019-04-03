#ifndef TABLE_HPP
#define TABLE_HPP

#include "gameobj.hpp"


class Table
        : public GameEntity
{
    Q_OBJECT

public:
    explicit Table(QObject * parent = nullptr)
        : GameEntity(parent) {}
};


#endif // TABLE_HPP
