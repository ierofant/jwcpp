#include <iostream>
#include <sstream>
#include <jwcpp/object.hpp>
#include <jwcpp/property.hpp>

static const char *msg = "{\"int\":5, \"double\":123.456}";

class Object : public JWCpp::Object
{
    public:
	Object() : integer(*this, "int"), xdouble(*this, "double"){}

    public:
	JWCpp::Property<int> integer;
	JWCpp::Property<double> xdouble;
};

int main()
{
    Object object;

    std::istringstream in(msg);
    in >> object;

    std::cout << "int:\t" << *object.integer << std::endl;
    std::cout << "double:\t" << *object.xdouble << std::endl;

    return 0;
}
