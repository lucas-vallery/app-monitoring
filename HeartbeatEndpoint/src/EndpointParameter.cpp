/* Header Include */
#include "../hdr/EndpointParameter.h"

/* Getters and Setters */
std::string EndpointParameter::GetName() {
    return _name;
}

std::string EndpointParameter::GetType() {
    return _type;
}

std::string EndpointParameter::GetValue() {
    return _value;
}

void EndpointParameter::SetName(std::string p_name) {
    _name = p_name;
}

void EndpointParameter::SetType(std::string p_type) {
    _type = p_type;
}   

void EndpointParameter::SetValue(std::string p_value) {
    _value = p_value;
}