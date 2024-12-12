#ifndef ENDPOINTPARAMETER_H
#define ENDPOINTPARAMETER_H

#include <string>
#include <unistd.h>
#include "../../json/include/nlohmann/json.hpp"

using json = nlohmann::json;

class EndpointParameter {
public:
    /* Constructors */
    EndpointParameter() = default;
    EndpointParameter(const std::string& p_name,
                      const std::string& p_type,
                      const std::string& p_value);

    /* Getters and Setters */
    std::string GetName() const;
    std::string GetType() const;
    template<typename type>
    type GetValue() const;
    void SetName(const std::string& p_name);
    void SetType(const std::string& p_type);
    void SetValue(const std::string& p_value);

    /* Public Methods */
    int FromJson(const json& j);

private:
    /* Private Members */
    std::string _name;
    std::string _type;
    union { 
        std::string* _string; 
        uint8_t _uint8; 
        uint16_t _uint16;
        uint32_t _uint32;
        uint64_t _uint64;
        int8_t _int8;
        int16_t _int16;
        int32_t _int32;
        int64_t _int64;
        bool _bool;
    };

    /* Private Methods */
    void StringToData(const std::string& p_str);
    

};

#endif