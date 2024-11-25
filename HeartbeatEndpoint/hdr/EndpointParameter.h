#ifndef ENDPOINTPARAMETER_H
#define ENDPOINTPARAMETER_H

#include <string>
#include <unistd.h>
#include <vector>

class EndpointParameter {
public:
    /* Constructors */
    EndpointParameter() = default;
    EndpointParameter(const std::string p_name,
                      const std::string p_type,
                      const std::string p_value) :
                      _name(p_name),
                      _type(p_type),
                      _value(p_value) {}

    /* Getters and Setters */
    std::string GetName();
    std::string GetType();
    std::string GetValue();
    void SetName(std::string p_name);
    void SetType(std::string p_type);
    void SetValue(std::string p_value);

private:
    /* Pruvate members */
    std::string _name;
    std::string _type;
    std::string _value;

};

#endif