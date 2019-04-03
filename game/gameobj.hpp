#ifndef GAMEOBJ_HPP
#define GAMEOBJ_HPP

#include <QEntity>
#include <QVector3D>


class GameEntity
        : public Qt3DCore::QEntity
{
    Q_OBJECT
    Q_PROPERTY(QVector3D position READ getPos WRITE setPos NOTIFY posChanged)

public:
    explicit GameEntity(QObject * /*parent*/ = nullptr) {}

    QVector3D getPos() const;
    void setPos(QVector3D pos);

signals:
    void posChanged();

private:
    QVector3D position{};
};


#endif // GAMEOBJ_HPP
