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
    int CheckHeartbeat(uint64_t* p_pHbIndex) override;

private:
    /* Private Methods */
    int CreatePipe();
    int OpenPipe();

    /* Private Members */
    int _pipeFd;
    std::string _pipePath;
};

#endif