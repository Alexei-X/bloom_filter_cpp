#include <iostream>
#include "HashFunctionFactory.hpp"

int main() {

    std::cout << "Hello world !" << std::endl;
    HashFunctionFactory factory = HashFunctionFactory();
    std::unique_ptr<HashFunction<std::string>> fct = factory.createHashFunction<std::string>(600881);
    std::cout << fct->getIndex("Bonjour") << std::endl;

    return 0;
}
