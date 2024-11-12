#ifndef HBINTERFACE_PIPE_H
#define HBINTERFACE_PIPE_H

/* Abstract Class Include */
#include "RcvInterface.h"

/* Librairy Includes */
#include <string>

class RcvInterface_Pipe : public RcvInterface {
public:
    /* Constructor */
    RcvInterface_Pipe(std::string* p_pPipePath);

    /* Destructor */
    ~RcvInterface_Pipe() override;

    /* Public Methods */
    int ReceiveHeartBeat(uint64_t* p_pHbIndex) override;

private:
    /* Private Methods */
    int OpenPipe(std::string* p_pPipePath);
    int ReadPipe();

    /* Private Members */
    int _pipeFd;
};

#endif