#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <QObject>
#include <QQmlEngine>
#include <QtGlobal>


class Engine
        : public QObject
{
    Q_OBJECT
    Q_PROPERTY(State state READ getState WRITE setState NOTIFY stateChanged)

public:
    enum class State {
        GAME, MENU
    };
    Q_ENUMS(State)

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
     State state;
};


#endif // ENGINE_HPP
