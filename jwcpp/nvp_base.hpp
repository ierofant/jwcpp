#ifndef _JWCPP_NVP_BASE_HPP_
#define _JWCPP_NVP_BASE_HPP_

#include "object.hpp"

namespace JWCpp
{
    class NvpBase
    {
	public:
	    virtual ~NvpBase = 0;

	protected:
	    NvpBase(Object &_object, const std::string &_name);

	private:
	    Object &object;
	    const std::string name;
    };
}

#endif //_JWCPP_NVP_BASE_HPP_
