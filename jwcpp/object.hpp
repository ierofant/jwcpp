#ifndef _JWCPP_OBJECT_HPP_
#define _JWCPP_OBJECT_HPP_

#include <string>
#include <unordered_map>

namespace JWCpp
{
    class NvpBase;
    class Object
    {
	private:
	    typedef std::unordered_map<std::string, NvpBase*> MapNvp;

	private:
	    MapNvp map_nvp;

	friend class JWCpp::NvpBase;
    };
}

#endif //_JWCPP_OBJECT_HPP_
