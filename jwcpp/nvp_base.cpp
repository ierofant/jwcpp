#include "nvp_base.hpp"

JWCpp::NvpBase::~NvpBase()
{
    auto itr = object.map_nvp.find(name);
    if(itr != object.map_nvp.end()) object.map_nvp.erase(itr);
}

JWCpp::NvpBase::NvpBase(Object &_object, const std::string &_name)
    : object(_object),
      name(_name)
{
    object.map_nvp[_name] = this;
}
