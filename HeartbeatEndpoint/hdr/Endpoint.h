#ifndef ENDPOINT_H
#define ENDPOINT_H

#define PARAM_ARRAY_SIZE 8

#include "../../json/include/nlohmann/json.hpp"
#include <string>
#include "EndpointParameter.h"
#include "../../HeartbeatReceiver/hdr/HeartbeatReceiverFactory.h"

using json = nlohmann::json;

class Endpoint {
public:
    /* Constructor */
    Endpoint() = default;
    Endpoint(const std::string& p_name,
             const std::string& p_method,
             const std::string& p_description,
             const EndpointParameter p_paramArray[]);

    /* Public Methods */
    int FromJson(const json& j);

private:
    /* Private Members */
    std::string _name;
    std::string _method;
    std::string _description;
    EndpointParameter _paramArray[8];
    size_t _arraySize;
    std::unique_ptr<HeartbeatReceiver> _heartbeatReceiver;

    /* Private Methods */
    EndpointParameter* FindParameterByName(const EndpointParameter* p_paramArray,
                                           size_t p_arraySize,
                                           const std::string& p_name);
    void CreateHeartbeatReceiverFromParam();

};

#endif