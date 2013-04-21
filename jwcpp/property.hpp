#ifndef _JWCPP_PROPERTY_HPP_
#define _JWCPP_PROPERTY_HPP_

#include <vector>
#include <algorithm>
#include "property_simple.hpp"

namespace JWCpp
{
    template<typename T, typename Enable = void>
    class Property;

    template<typename T>
    class Property<T, typename std::enable_if<std::is_base_of<JWCpp::Object, T>::value>::type> : public JWCpp::PropertySimple<T>
    {
	public:
	    Property(Object &_object, const std::string &_name) : JWCpp::PropertySimple<T>(_object, _name) {}
	    virtual ~Property() = default;

	protected:
	    virtual void push_to_stream(std::ostream &_out) const override {_out << this->get_value();}
	    virtual void pop_from_stream(std::istream &_in) override {if(_in.good()) _in >> this->get_value();}
    };

    template<typename T>
    class Property<T, typename std::enable_if<std::is_fundamental<T>::value>::type> : public JWCpp::PropertySimple<T>
    {
	public:
	    Property(Object &_object, const std::string &_name) : JWCpp::PropertySimple<T>(_object, _name) {}
	    virtual ~Property() = default;

	protected:
	    virtual void push_to_stream(std::ostream &_out) const override {_out << this->get_value();}
	    virtual void pop_from_stream(std::istream &_in) override {if(_in.good()) _in >> this->get_value();}
    };

    template<typename T>
    class Property<std::vector<T>> : public JWCpp::PropertySimple<std::vector<T>>
    {
	public:
	    Property(Object &_object, const std::string &_name) : JWCpp::PropertySimple<std::vector<T>>(_object, _name) {}
	    virtual ~Property() = default;

	protected:
	    virtual void push_to_stream(std::ostream &_out) const override
	    {
		_out << '[';

		bool is_first = true;
		for(auto &x: this->get_value())
		{
		    if(is_first) is_first = false;
		    else _out << ',';
		    
		    JWCpp::Property<T> property(const_cast<JWCpp::Object&>(this->get_object()), "");
		    property.set_value(x);
		    _out << property;
		}

		_out << ']';
	    }
    	    virtual void pop_from_stream(std::istream &_in) override 
	    {
		std::vector<T> &value = this->get_value();
		value.clear();		

		_in >> std::ws;
		if(_in.get() == '[')
		{
		    while(_in.good())
		    {
			JWCpp::Property<T> property(this->get_object(), "");
			_in >> std::ws >> property;
			value.push_back(*property);
			
			_in >> std::ws;
			if(_in.get() != ',') break;
		    }
		}
	    }
    };

    template<>
    class Property<std::string> : public JWCpp::PropertySimple<std::string>
    {
	public:
	    Property(Object &_object, const std::string &_name) : JWCpp::PropertySimple<std::string>(_object, _name) {}
	    virtual ~Property() = default;

	protected:
	    virtual void push_to_stream(std::ostream &_out) const override {_out << '"' << this->get_value() << '"';}
	    virtual void pop_from_stream(std::istream &_in) override 
	    {
		std::string &value = this->get_value();
		value.clear();

		_in >> std::ws;

		if(_in.get() == '"')
		    for(int sym = _in.get(); _in.good() && sym != '"'; sym = _in.get())
			value += sym;
	    }
    };
}

#endif //_JWCPP_PROPERTY_HPP_
