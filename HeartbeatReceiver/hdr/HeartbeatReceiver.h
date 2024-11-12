#ifndef HEARTBEATRECEIVER_H
#define HEARTBEATRECEIVER_H

#include <cstdint>

class HeartbeatReceiver {
public:
    virtual ~HeartbeatReceiver() {};
    virtual int ReceiveHeartbeat(uint64_t* p_pHbIndex) = 0;
};

#endif