#include "HeartbeatReceiver/hdr/HeartbeatReceiverFactory.h"
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <fstream>
#include "json/include/nlohmann/json.hpp"

#include "HeartbeatEndpoint/hdr/EndpointParameter.h"

  //std::unique_ptr<HeartbeatReceiver> hbRcvPipe = HeartbeatReceiverFactory::CreateReceiver("pipe", "/tmp/mypipe");
  //hbRcvPipe->ReceiveHeartbeat(&hbIndex);


using json = nlohmann::json;

int ValidateJson(const json& p_jsonData, const std::vector<std::string>& p_requiredFields){ 
    for (const auto& l_field : p_requiredFields) { 
        if (!p_jsonData.contains(l_field)) { 
            return -1; 
        }
    } 
    return 0; 
}

int ParseEndpointParam() {

}

int main(int argc, char *argv[]) {
    std::string l_jsonPath;
    json l_jsonData;
    
    /* Handle arguments */
    /*
    if(argc != 2) {
        std::cerr << "Arguments are wrong" << std::endl;
        return -1;
    }
    l_jsonPath = argv[1];
    */

    /* Handling Json */
    /*
    std::ifstream l_jsonFile(l_jsonPath);
    if (!l_jsonFile.is_open()) { 
        std::cerr << "Failed to open JSON file" << std::endl; 
        l_jsonFile.close();
        return -1;
    }
    
    l_jsonFile >> l_jsonData;
    l_jsonFile.close();

    if(ValidateJson(l_jsonData, {"name", "logPath", "endpoints"}) != 0) {
        std::cerr << "Json file format is wrong" << std::endl;
        return -1;
    }
    */

    EndpointParameter newParam;
        
    newParam.SetName("name");
    newParam.SetType("uint64");
    newParam.SetValue("1279");

    std::cout << std::to_string(newParam.GetValue<uint64_t>()) << std::endl;
   
    return 0;
}