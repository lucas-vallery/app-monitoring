
#include "HeartbeatReceiver/hdr/HeartbeatReceiverFactory.h"
#include <iostream>
#include <memory>

int main(void) {

    HeartbeatReceiverFactory::CreateReceiver("pipe", "tmp/pipe");

    std::cout << "Hello Wolrd!";
    return 0;
}