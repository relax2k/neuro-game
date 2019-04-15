#pragma once

#include "stdafx.hpp"

#include "updateposjob.hpp"


class MoveBackend;


class MoveAspect
        : public Qt3DCore::QAbstractAspect
{
    Q_OBJECT

public:
    explicit MoveAspect(QObject * parent = nullptr);

    void addBack(Qt3DCore::QNodeId id, MoveBackend * mover);
    MoveBackend * back(Qt3DCore::QNodeId id);
    MoveBackend * takeBack(Qt3DCore::QNodeId id);

protected:
    QVector<Qt3DCore::QAspectJobPtr> jobsToExecute(qint64 time) override;

private:
    QHash<Qt3DCore::QNodeId, MoveBackend *> ms_;
    UpdatePosJobPtr updatePosJob_;
};
