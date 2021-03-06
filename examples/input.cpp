#include <iostream>
#include <sstream>
#include <jwcpp/object.hpp>
#include <jwcpp/property.hpp>

static const char *msg = R"({"boolean": true, "int": 5, "double": 123.456, "list": ["one", "two", "three"]})";

class Object : public JWCpp::Object
{
    public:
	Object() : boolean(*this, "boolean"), integer(*this, "int"), xdouble(*this, "double"), list(*this, "list"){}

    public:
	JWCpp::Property<bool> boolean;
	JWCpp::Property<int> integer;
	JWCpp::Property<double> xdouble;
	JWCpp::Property<std::vector<std::string>> list;
};

int main()
{
    Object object;
    std::istringstream in(msg);
    in >> object;

    std::cout << std::boolalpha;
    std::cout << "boolean:\t" << *object.boolean << std::endl;
    std::cout << "int:\t" << *object.integer << std::endl;
    std::cout << "double:\t" << *object.xdouble << std::endl;
    
    std::cout << "list:\t";
    for(auto &x : *object.list) std::cout << x << ' ';
    std::cout << std::endl; 

    return 0;
}
