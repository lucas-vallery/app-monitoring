#ifndef HEARTBEATRECEIVERFACTORY_H
#define HEARTBEATRECEIVERFACTORY_H

/* Header Includes */
#include "HeartbeatReceiver.h"
#include "HeartbeatReceiver_Pipe.h"

/* Librairy Includes */
#include <memory>
#include <functional>
#include <unordered_map>
#include <iostream>

class HeartbeatReceiverFactory {

public:
    /* Public Methods */
    template<typename... Args>
    static std::unique_ptr<HeartbeatReceiver> CreateReceiver(const std::string& p_type, Args&&... p_args) {
        std::cout << "Entering factory" << std::endl;
        if(p_type.compare("pipe") == 0) {
            std::cout << "Creating pipe" << std::endl;
            return std::make_unique<HeartbeatReceiver_Pipe>(std::forward<Args>(p_args)...);
        }
        return nullptr;
    };
};

#endif