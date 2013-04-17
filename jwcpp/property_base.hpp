#ifndef _JWCPP_PROPERTY_BASE_HPP_
#define _JWCPP_PROPERTY_BASE_HPP_

#include <string>
#include <ostream>
#include <istream>

namespace JWCpp
{
    class Object;
    class PropertyBase
    {
	public:
	    virtual ~PropertyBase() = 0;

	public:
	    virtual void init();
	    virtual void reset();
	    const Object& get_object() const;
	    bool is_init() const;
	    Object& get_object();

	protected:
	    PropertyBase(JWCpp::Object &_object, const std::string &_name);

	protected:
	    virtual void push_to_stream(std::ostream &_out) const = 0;
	    virtual void pop_from_stream(std::istream &_in) = 0;

	private:
	    Object &object;
	    const std::string name;
	    bool is_init_;

	friend std::ostream& JWCpp::operator<<(std::ostream &_out, const JWCpp::PropertyBase &_property);
	friend std::istream& JWCpp::operator>>(std::istream &_in, JWCpp::PropertyBase &_property);
    };
    
    std::ostream& operator<<(std::ostream &_out, const JWCpp::PropertyBase &_property);
    std::istream& operator>>(std::istream &_in, JWCpp::PropertyBase &_property);
}

#endif //_JWCPP_PROPERTY_BASE_HPP_
