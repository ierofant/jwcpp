#ifndef _JWCPP_OBJECT_HPP_
#define _JWCPP_OBJECT_HPP_

#include <string>
#include <unordered_map>
#include <ostream>
#include <istream>

namespace JWCpp
{
    class PropertyBase;
    class Object
    {
	private:
	    typedef std::unordered_map<std::string, PropertyBase*> Properties;

	private:
	    Properties properties;

	friend class JWCpp::PropertyBase;
	friend std::ostream& JWCpp::operator<<(std::ostream &_out, const JWCpp::Object &_object);
	friend std::istream& JWCpp::operator>>(std::istream &_in, JWCpp::Object &_object);
    };

    std::ostream& operator<<(std::ostream &_out, const JWCpp::Object &_object);
    std::istream& operator>>(std::istream &_in, JWCpp::Object &_object);
}

#endif //_JWCPP_OBJECT_HPP_
