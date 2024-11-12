#ifndef RCVINTERFACE_H
#define RCVINTERFACE_H

#include <cstdint>

class RcvInterface {
public:
    virtual ~RcvInterface() {};
    virtual int ReceiveHeartBeat(uint64_t* p_pHbIndex) = 0;
};

#endif