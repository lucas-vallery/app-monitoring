/* Abstract Parent Class Include */
#include "HeartbeatSender.h"

/* Librairy Includes */
#include <cstring>

class HeartbeatSender_Pipe : public HeartbeatSender {
    /* Constructor */
    HeartbeatSender_Pipe(std::string* p_pPipePath);
    /* Destructor */
    ~HeartbeatSender_Pipe() override;

public:
    /* Public Methods */
    int SendHeartbeat(uint64_t p_pHbIndex) override;

private:
    /* Private Methods */
    int OpenPipe(std::string* p_pPipePath);

    /* Private Members */
    int _pipeFd;
};