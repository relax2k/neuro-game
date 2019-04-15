#pragma once

#include "stdafx.hpp"


class MoveAspect;


class UpdatePosJob
        : public Qt3DCore::QAspectJob {
public:
    explicit UpdatePosJob(MoveAspect * aspect);

    void run() override;

private:
    MoveAspect * aspect_;
};


using UpdatePosJobPtr = QSharedPointer<UpdatePosJob>;
