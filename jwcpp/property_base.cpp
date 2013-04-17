#include "property_base.hpp"
#include "object.hpp"

JWCpp::PropertyBase::~PropertyBase()
{
    auto itr = object.properties.find(name);
    if(itr != object.properties.end() && itr->second == this) object.properties.erase(itr);
}

void JWCpp::PropertyBase::init()
{
    is_init_ = true;
}

void JWCpp::PropertyBase::reset()
{
    is_init_ = false;
}

const JWCpp::Object& JWCpp::PropertyBase::get_object() const
{
    return object;
}

bool JWCpp::PropertyBase::is_init() const
{
    return is_init_;
}

JWCpp::Object& JWCpp::PropertyBase::get_object()
{
    return object;
}

JWCpp::PropertyBase::PropertyBase(JWCpp::Object &_object, const std::string &_name)
    : object(_object),
      name(_name),
      is_init_(false)
{
    object.properties[name] = this;
}


std::ostream& JWCpp::operator<<(std::ostream &_out, const JWCpp::PropertyBase &_property)
{
    _property.push_to_stream(_out);
    return _out;
}

std::istream& JWCpp::operator>>(std::istream &_in, JWCpp::PropertyBase &_property)
{
    _property.pop_from_stream(_in);
    return _in;
}
