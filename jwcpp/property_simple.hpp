#ifndef _JWCPP_PROPERTY_SIMPLE_HPP_
#define _JWCPP_PROPERTY_SIMPLE_HPP_

#include "property_base.hpp"

namespace JWCpp
{
    template<typename T>
    class PropertySimple : public JWCpp::PropertyBase
    {
	public:
	    const T& operator*() const {return get_value();}
	    const T* operator->() const {return &get_value();}
	    T& operator*() {return get_value();}
	    T* operator->() {return &get_value();}

	public:
	    const T& get_value() const {return value;}
	    T& get_value() 
	    {
		init();
		return value;
	    }
	    void set_value(const T &_value)
	    {
		init();
		value = _value;
	    }

	protected:
	    PropertySimple(Object &_object, const std::string &_name) : PropertyBase(_object, _name) {}

	private:
	    T value;    
    };
}

#endif //_JWCPP_PROPERTY_SIMPLE_HPP_
