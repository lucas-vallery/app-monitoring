#ifndef HEARTBEATRECEIVER_H
#define HEARTBEATRECEIVER_H

#include <cstdint>

class HeartbeatReceiver {
public:
    virtual ~HeartbeatReceiver() {};
    virtual int CheckHeartbeat(uint64_t* p_pHbIndex);
};

#endif