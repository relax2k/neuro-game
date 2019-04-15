#include "moveaspect.hpp"

#include "movebackend.hpp"
#include "movable.hpp"


MoveAspect::MoveAspect(QObject * parent)
    : Qt3DCore::QAbstractAspect(parent)
    , updatePosJob_(new UpdatePosJob(this))
{
    auto mapper = QSharedPointer<MoveMapper>::create(this);
    registerBackendType<Movable>(mapper);
}


void MoveAspect::addBack(Qt3DCore::QNodeId id, MoveBackend * mover)
{
    ms_.insert(id, mover);
}


MoveBackend * MoveAspect::back(Qt3DCore::QNodeId id)
{
    return ms_.value(id, nullptr);
}


MoveBackend * MoveAspect::takeBack(Qt3DCore::QNodeId id)
{
    return ms_.take(id);
}


QVector<Qt3DCore::QAspectJobPtr> MoveAspect::jobsToExecute(qint64 time)
{
    qDebug() << Q_FUNC_INFO << "Frame time =" << time;
    return { updatePosJob_ };
}
