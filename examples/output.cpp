#include <iostream>
#include <jwcpp/object.hpp>
#include <jwcpp/property.hpp>

class SubObject : public JWCpp::Object
{
    public:
	SubObject() : x(*this, "x") {}

    public:
	JWCpp::Property<double> x;
};

class Object : public JWCpp::Object
{
    public:
	Object() : integer(*this, "int"), xdouble(*this, "double"), name(*this, "name"), list(*this, "list"), sub(*this, "sub") {}

    public:
	JWCpp::Property<int> integer;
	JWCpp::Property<double> xdouble;
	JWCpp::Property<std::string> name;
	JWCpp::Property<std::vector<int>> list;
	JWCpp::Property<SubObject> sub;
};

int main()
{
    Object object;
    object.integer.set_value(7);
    object.xdouble.set_value(3.45);
    object.name.set_value("Peter Piper");
    *object.list = {1, 2, 3, 4, 5};
    object.sub->x.set_value(67);

    std::cout << object << std::endl;

    return 0;
}
