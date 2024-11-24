/* Header Include */
#include "../hdr/HeartbeatSender_Pipe.h"

/* Library Includes */
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cassert>
#include <cstdlib>

/* Constructor */
HeartbeatSender_Pipe::HeartbeatSender_Pipe(std::string* p_pPipePath) {
    OpenPipe(p_pPipePath);
}

/* Destructor */
HeartbeatSender_Pipe::~HeartbeatSender_Pipe() {
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
int HeartbeatSender_Pipe::SendHeartbeat(uint64_t p_hbIndex) {
    int l_ret;
    std::string l_strBuff;

    /* Check id pipe file descriptor is valid */
    if(_pipeFd == -1) {
        return -1;
    }

    l_strBuff = std::to_string(p_hbIndex);

    l_ret = write(_pipeFd, l_strBuff.c_str(), strlen(l_strBuff.c_str()));
    if(l_ret == -1) {
        return -1;
    }
    
    return 0;
}

/* Private Methods */
int HeartbeatSender_Pipe::OpenPipe(std::string* p_pPipePath) {
    assert(p_pPipePath == nullptr);

    int l_ret = 0;

    _pipeFd = open(p_pPipePath->c_str(), O_WRONLY | O_NONBLOCK);
    if(_pipeFd == -1) {
        l_ret = -1;
    } else {
        l_ret = 0;
    }

    return l_ret;
}