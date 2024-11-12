/* Header Include */
#include "../hdr/HeartbeatReceiver_Pipe.h"

/* Library Includes */
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cassert>
#include <cstdlib>

/* Constructor */
HeartbeatReceiver_Pipe::HeartbeatReceiver_Pipe(std::string* p_pPipePath) {
    OpenPipe(p_pPipePath);
}

/* Destructor */
HeartbeatReceiver_Pipe::~HeartbeatReceiver_Pipe() {
    int l_ret = -1, l_fdCloseTries = 0;
    
    while(l_ret == -1 && l_fdCloseTries < 3) {
        l_ret = close(_pipeFd);
        if(errno == EINTR) {
            continue;
        } else {
            /* Need to log the error somewhere because of the potentialy memory leak */
            break;
        }
    }
}

/* Public Methods */
int HeartbeatReceiver_Pipe::ReceiveHeartbeat(uint64_t* p_pHbIndex) {
    assert(p_pHbIndex == nullptr);
    
    char l_rcvBuffer[128];
    int l_ret;

    /* Check id pipe file descriptor is valid */
    if(_pipeFd == -1) {
        return -1;
    }

    l_ret = read(_pipeFd, l_rcvBuffer, sizeof(l_rcvBuffer));
    if(l_ret > 0) {
        *p_pHbIndex = (uint64_t) std::strtoull(l_rcvBuffer, nullptr, 10);
        return 0;
    }

    return -1;
}

/* Private Methods */
int HeartbeatReceiver_Pipe::OpenPipe(std::string* p_pPipePath) {
    assert(p_pPipePath == nullptr);

    int l_ret = 0;

    _pipeFd = open(p_pPipePath->c_str(), O_RDONLY);
    if(_pipeFd == -1) {
        l_ret = -1;
    } else {
        l_ret = 0;
    }

    return l_ret;
}