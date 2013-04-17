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
	    virtual void pop_from_stream(std::istream &_in) override {_in >> this->get_value();}
    };

    template<typename T>
    class Property<T, typename std::enable_if<std::is_fundamental<T>::value>::type> : public JWCpp::PropertySimple<T>
    {
	public:
	    Property(Object &_object, const std::string &_name) : JWCpp::PropertySimple<T>(_object, _name) {}
	    virtual ~Property() = default;

	protected:
	    virtual void push_to_stream(std::ostream &_out) const override {_out << this->get_value();}
	    virtual void pop_from_stream(std::istream &_in) override {_in >> this->get_value();}
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
		auto func = [&](const T &_value)
		{
		    if(is_first) is_first = false;
		    else _out << ',';

		    JWCpp::Property<T> property(this->get_object(), "");
		    _out << property;
		};
		std::for_each(this->get_value().begin(), this->get_value().end(), &func);
		_out << ']';
	    }
    	    virtual void pop_from_stream(std::istream &_in) override {}
    };

    template<>
    class Property<std::string> : public JWCpp::PropertySimple<std::string>
    {
	public:
	    Property(Object &_object, const std::string &_name) : JWCpp::PropertySimple<std::string>(_object, _name) {}
	    virtual ~Property() = default;

	protected:
	    virtual void push_to_stream(std::ostream &_out) const override {_out << '"' << this->get_value() << '"';}
	    virtual void pop_from_stream(std::istream &_in) override {}
    };
}

#endif //_JWCPP_PROPERTY_HPP_
