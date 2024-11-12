#ifndef HEARTBEATSENDER_H
#define HEARTBEATSENDER_H

#include <cstdint>

class HeartbeatSender {
public:
    virtual ~HeartbeatSender() {};
    virtual int SendHeartbeat(uint64_t p_pHbIndex) = 0;
};

#endif