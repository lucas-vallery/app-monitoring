/* Header Include */
#include "../hdr/Endpoint.h"

/* Privat Includes */
#include <algorithm>

/* Constructor */
Endpoint::Endpoint(const std::string& p_name,
            const std::string& p_method,
            const std::string& p_description,
            const EndpointParameter p_paramArray[]) :
            _name(p_name),
            _method(p_method),
            _description(p_description)
{
    _arraySize = sizeof(p_paramArray) / sizeof(p_paramArray[0]);
    _arraySize = _arraySize > PARAM_ARRAY_SIZE ? PARAM_ARRAY_SIZE : _arraySize;

    std::copy(p_paramArray, p_paramArray + _arraySize, _paramArray);

}

/* Public Methods */
int Endpoint::FromJson(const json& j) {

}

/* Private Methods */
EndpointParameter* Endpoint::FindParameterByName(const EndpointParameter* p_paramArray,
                                                 size_t p_arraySize,
                                                 const std::string& p_name) {
    if (p_paramArray == nullptr || p_arraySize == 0) {
        return nullptr;
    }
    
    for(int i = 0; i < p_arraySize; i++) {
        if(p_paramArray[i].GetName() == p_name) {
            return (EndpointParameter*) &p_paramArray[i];
        }
    }
    return nullptr;
}

void Endpoint::CreateHeartbeatReceiverFromParam() {
    
}