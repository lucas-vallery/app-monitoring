/* Header Include */
#include "../hdr/EndpointParameter.h"

/* Constructor */
EndpointParameter::EndpointParameter(const std::string& p_name,
                                     const std::string& p_type,
                                     const std::string& p_value):
                                     _name(p_name),
                                     _type(p_type)
{
    StringToData(p_value);
}

/* Getters and Setters */
std::string EndpointParameter::GetName() const {
    return _name;
}

std::string EndpointParameter::GetType() const {
    return _type;
}

template<>
std::string EndpointParameter::GetValue<std::string>() const {
    return *_string;
}

template<>
uint8_t EndpointParameter::GetValue<uint8_t>() const {
    return _uint8;
}

template<>
uint16_t EndpointParameter::GetValue<uint16_t>() const {
    return _uint16;
}

template<>
uint32_t EndpointParameter::GetValue<uint32_t>() const {
    return _uint32;
}

template<>
uint64_t EndpointParameter::GetValue<uint64_t>() const {
    return _uint64;
}

template<>
int8_t EndpointParameter::GetValue<int8_t>() const {
    return _int8;
}

template<>
int16_t EndpointParameter::GetValue<int16_t>() const {
    return _int16;
}

template<>
int32_t EndpointParameter::GetValue<int32_t>() const {
    return _int32;
}

template<>
int64_t EndpointParameter::GetValue<int64_t>() const {
    return _int64;
}

void EndpointParameter::SetName(const std::string& p_name) {
    _name = p_name;
}

void EndpointParameter::SetType(const std::string& p_type) {
    _type = p_type;
}   

void EndpointParameter::SetValue(const std::string& p_value) {
    StringToData(p_value);
}

/* Public Methods */

int EndpointParameter::FromJson(const json& p_json) {
    if(!p_json.contains("name") || !p_json.contains("type") || !p_json.contains("value")) {
        return -1;
    }

    _name = p_json.at("name").get<std::string>();
    _type = p_json.at("type").get<std::string>();
    StringToData(p_json.at("value").get<std::string>());
    return 0;
}

/* Private Methods */
void EndpointParameter::StringToData(const std::string& p_str) {
    if(_type == "string") {
        _string = new std::string(p_str);
    } else if(_type == "uint8") {
        _uint8 = (uint8_t) std::stoi(p_str);
    } else if(_type == "uint16") {
        _uint16 = (uint16_t) std::stoi(p_str);
    } else if(_type == "uint32") {
        _uint32 = (uint32_t) std::stoi(p_str);
    } else if(_type == "uint64") {
        _uint64 = (uint64_t) std::stoi(p_str);
    } else if(_type == "int8") {
        _int8 = (int8_t) std::stoi(p_str);
    } else if(_type == "int16") {
        _int16 = (int16_t) std::stoi(p_str);
    } else if(_type == "int32") {
        _int32 = (int32_t) std::stoi(p_str);
    } else if(_type == "int64") {
        _int64 = (int64_t) std::stoi(p_str);
    } else if(_type == "bool") {
        _bool = (p_str == "true");
    }
}