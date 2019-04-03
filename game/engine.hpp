#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <memory>
#include <vector>

#include <QObject>
#include <QQmlEngine>
#include <QVector3D>
#include <QtGlobal>

#include "ball.hpp"
#include "camera.hpp"
#include "updatable.hpp"


class Engine
        : public QObject
{
    Q_OBJECT
    Q_PROPERTY(State state READ getState WRITE setState NOTIFY stateChanged)

public:
    enum class State {
        GAME, MENU
    };
    Q_ENUM(State)

public:
    explicit Engine(QObject * parent = nullptr)
        : QObject(parent) {} // TODO(Yuki/make singleton)

    Q_INVOKABLE void init();
    Q_INVOKABLE void update();

    void  setState(State st);
    State getState() const;

signals:
    void stateChanged();


private:
    void menuInit() const;
    void gameInit() const;

private:
    const QVector3D CAM_MENU_POS_ = {30, 30, 50};

    std::vector<std::shared_ptr<Updatable>> components_;

    State state{};
    int64_t time_{};
    int64_t interval_ms_ = 5; // WARNING(same as in qml) TODO(add assert)
};

Q_DECLARE_METATYPE(Engine::State)


#endif // ENGINE_HPP
