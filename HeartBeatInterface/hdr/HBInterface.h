#ifndef HEARTBEATINTERFACE_H
#define HEARTBEATINTERFACE_H

class HBInterface {
public:
    virtual ~HBInterface() {};
    virtual bool ReceiveHeartBeat() = 0;
};

#endif