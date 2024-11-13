/* Header Include */
#include "../hdr/HeartbeatReceiverFactory.h"

/* Library Includes */
#include <string>

std::unique_ptr<HeartbeatReceiver> HeartbeatMediaFactor::CreateReceiver(const std::string& p_type) {
    if(p_type.compare("pipe") == 0) {
        return std::make_unique<HeartbeatReceiver_Pipe>();
    }
    return nullptr;
};