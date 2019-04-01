#ifndef TABLE_HPP
#define TABLE_HPP

#include "gameobj.hpp"


class Table
        : public GameObj
{
    Q_OBJECT

public:
    explicit Table(QObject * parent = nullptr)
        : GameObj(parent) {}
};


#endif // TABLE_HPP
