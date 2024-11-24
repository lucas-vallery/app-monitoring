#include "HeartbeatReceiver/hdr/HeartbeatReceiverFactory.h"
#include <iostream>
#include <memory>

#include <thread>
#include <chrono>

int main(void) {
    uint64_t hbIndex = 0;

    std::cout << "Hello Wolrd!" << std::endl;

    std::unique_ptr<HeartbeatReceiver> hbRcvPipe = HeartbeatReceiverFactory::CreateReceiver("pipe", "/tmp/mypipe");
    //hbRcvPipe->ReceiveHeartbeat(&hbIndex);
    

    return 0;
}