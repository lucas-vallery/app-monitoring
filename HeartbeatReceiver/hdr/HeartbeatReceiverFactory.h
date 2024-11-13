#ifndef HEARTBEATRECEIVERFACTORY_H
#define HEARTBEATRECEIVERFACTORY_H

/* Header Includes */
#include "HeartbeatReceiver.h"
#include "HeartbeatReceiver_Pipe.h"

/* Librairy Includes */
#include <memory>

class HeartbeatMediaFactor {

public:
    /* Public Methods */
    static std::unique_ptr<HeartbeatReceiver> CreateReceiver(const std::string& p_type);
};

#endif