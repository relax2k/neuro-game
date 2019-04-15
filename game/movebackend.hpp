#pragma once

#include "stdafx.hpp"


class MoveBackend
        : public Qt3DCore::QBackendNode
{
public:
    MoveBackend();

private:
    void initializeFromPeer(
            Qt3DCore::QNodeCreatedChangeBasePtr const & change) override;
};


class MoveAspect;


class MoveMapper
        : public Qt3DCore::QBackendNodeMapper {
public:
    explicit MoveMapper(MoveAspect * aspect);

    Qt3DCore::QBackendNode * create(
            Qt3DCore::QNodeCreatedChangeBasePtr const & change) const override;

    Qt3DCore::QBackendNode * get(Qt3DCore::QNodeId id) const override;

    void destroy(Qt3DCore::QNodeId id) const override;

private:
    MoveAspect * aspect_;
};
