#include <algorithm>
#include "object.hpp"
#include "property_base.hpp"

std::ostream& JWCpp::operator<<(std::ostream &_out, const JWCpp::Object &_object)
{
    _out << '{';
    bool is_first = true;
    auto func = [&](const JWCpp::Object::Properties::value_type &_pair)
    {
	if(_pair.second->is_init())
	{
	    if(is_first) is_first = false;
	    else _out << ',';
	    _out << '"' << _pair.first << "\":" << *_pair.second;
	}
    };
    std::for_each(_object.properties.begin(), _object.properties.end(), func);

    _out << '}';
    return _out;
}

std::istream& JWCpp::operator>>(std::istream &_in, JWCpp::Object &_object)
{
    
    return _in;
}
