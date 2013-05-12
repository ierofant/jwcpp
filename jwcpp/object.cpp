#include <algorithm>
#include "object.hpp"
#include "property_base.hpp"

std::ostream& JWCpp::operator<<(std::ostream &_out, const JWCpp::Object &_object)
{
    _out << '{';

    bool is_first = true;
    for(auto &x:_object.properties)
    {
	if(x.second->is_init())
	{
	    if(is_first) is_first = false;
	    else _out << ',';
	    _out << '"' << x.first << "\":" << *x.second;
	}
    }

    _out << '}';
    return _out;
}

std::istream& JWCpp::operator>>(std::istream &_in, JWCpp::Object &_object)
{
    _in >> std::ws;
    if(_in.get() == '{')
    {
	while(_in.good())
	{
	    _in >> std::ws;
	    if(_in.get() != '"') break;

	    std::string name;
	    for(auto sym = _in.get(); _in.good() && sym != '"'; sym = _in.get()) name += sym;

	    _in >> std::ws;
	    if(_in.get() != ':') break;
	    
	    auto itr = _object.properties.find(name);
	    if(itr != _object.properties.end()) _in >> *(itr->second);
	    else
	    {
		unsigned depth = 0;
		while(_in.good())
		{
		    int sym = _in.get();
		    if(sym == '}')
		    {
			if(depth == 0) break;
			else --depth;
		    }
		    else if(sym == '{') ++depth;
		}
	    }

	    _in >> std::ws;
	    if(_in.get() != ',') break;
	}
    }

    return _in;
}
