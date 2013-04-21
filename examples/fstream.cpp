#include <iostream>
#include <fstream>
#include <jwcpp/object.hpp>
#include <jwcpp/property.hpp>

class Object : public JWCpp::Object
{
    public:
	Object() : coords(*this, "coords") {}

    public:
	JWCpp::Property<std::vector<std::vector<int>>> coords;
};

int main()
{
    std::ofstream out("file.json");
    Object obj1;
    obj1.coords->resize(4);
    (*obj1.coords)[0] = {0, 0};
    (*obj1.coords)[1] = {0, 10};
    (*obj1.coords)[2] = {10, 10};
    (*obj1.coords)[3] = {10, 0};
    out << obj1;
    out.close();

    Object obj2;
    std::cout << "[1]: " << obj2 << std::endl;
    
    std::ifstream in("file.json");
    in >> obj2;
    std::cout << "[2]: " << obj2 << std::endl;
    in.close();

    return 0;
}
