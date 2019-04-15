#include "updateposjob.hpp"


UpdatePosJob::UpdatePosJob(MoveAspect * aspect)
    : aspect_(aspect)
{
    Q_ASSERT(aspect_);
}


void UpdatePosJob::run()
{
    qDebug() << "I am job!";
}
