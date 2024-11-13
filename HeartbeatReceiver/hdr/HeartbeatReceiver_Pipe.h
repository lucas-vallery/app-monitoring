#ifndef HEARTBEATRECEIVER_PIPE_H
#define HEARTBEATRECEIVER_PIPE_H

/* Abstract Class Include */
#include "HeartbeatReceiver.h"

/* Librairy Includes */
#include <string>

class HeartbeatReceiver_Pipe : public HeartbeatReceiver {
public:
    /* Constructor */
    HeartbeatReceiver_Pipe(const std::string& p_pPipePath);

    /* Destructor */
    ~HeartbeatReceiver_Pipe() override;

    /* Public Methods */
    int ReceiveHeartbeat(uint64_t* p_pHbIndex) override;

private:
    /* Private Methods */
    int OpenPipe(const std::string& p_pPipePath);
    int ReadPipe();

    /* Private Members */
    int _pipeFd;
};

#endif