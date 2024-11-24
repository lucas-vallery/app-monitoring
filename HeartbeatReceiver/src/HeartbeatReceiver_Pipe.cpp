/* Header Include */
#include "../hdr/HeartbeatReceiver_Pipe.h"

/* Library Includes */
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <sys/stat.h>

/* Constructor */
HeartbeatReceiver_Pipe::HeartbeatReceiver_Pipe(const std::string& p_pPipePath):
_pipePath(p_pPipePath)
 {
    std::cout << "Pipe constructor" << std::endl;
    
    OpenPipe();
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
        /* Need to somehow delete the pipe */
    }
}

/* Public Methods */
int HeartbeatReceiver_Pipe::ReceiveHeartbeat(uint64_t* p_pHbIndex) {
    assert(p_pHbIndex != nullptr);
    
    char l_rcvBuffer[128];
    int l_ret;

    /* Check if named pipe file descriptor is valid */
    if(_pipeFd == -1) {
        return -1;
    }

    /* Read from named pipe */
    l_ret = read(_pipeFd, l_rcvBuffer, sizeof(l_rcvBuffer));
    if(l_ret > 0) {
        *p_pHbIndex = (uint64_t) std::strtoull(l_rcvBuffer, nullptr, 10);
        return 0;
    }

    return -1;
}

/* Private Methods */
int HeartbeatReceiver_Pipe::OpenPipe() {

    /* Check if the named pipe exists */
    if (access(_pipePath.c_str(), F_OK) == 0) {
        std::cout << "Named pipe " << _pipePath << " already exists." << std::endl;
    } else {
        /* Create named pipe */
        int result = mkfifo(_pipePath.c_str(), 0666);
        if (result != 0) {
            std::cerr << "Error creating named pipe: " << std::endl;
            return -1;
        }
    }

    /* Open named pipe in read only */
    _pipeFd = open(_pipePath.c_str(), O_RDONLY | O_NONBLOCK);
    if(_pipeFd == -1) {
        std::cout << "Opening pipe failed" << std::endl;
        return -1;
    }

    return 0;
}