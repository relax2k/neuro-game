#include "movebackend.hpp"

#include "moveaspect.hpp"


MoveBackend::MoveBackend()
    : Qt3DCore::QBackendNode(Qt3DCore::QBackendNode::ReadWrite)
{}


void MoveBackend::initializeFromPeer(
        Qt3DCore::QNodeCreatedChangeBasePtr const & change)
{
    // TODO: Implement me!
}


MoveMapper::MoveMapper(MoveAspect * aspect)
    : aspect_(aspect)
{
    Q_ASSERT(aspect_);
}


Qt3DCore::QBackendNode * MoveMapper::create(
        Qt3DCore::QNodeCreatedChangeBasePtr const & change) const {
    auto back = new MoveBackend;
    aspect_->addBack(change->subjectId(), back);
    return back;
}


Qt3DCore::QBackendNode * MoveMapper::get(Qt3DCore::QNodeId id) const {
    return aspect_->back(id);
}


void MoveMapper::destroy(Qt3DCore::QNodeId id) const {
    auto mover = aspect_->takeBack(id);
    delete mover;
}
