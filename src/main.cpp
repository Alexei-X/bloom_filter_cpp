#include <iostream>
#include "HashFunctionFactory.h"

int main() {

    std::cout << "Hello world !" << std::endl;
    HashFunctionFactory factory = HashFunctionFactory();
    std::unique_ptr<HashFunction> fct = factory.createHashFunction(600881);
    std::cout << fct->getIndex(5) << std::endl;

    return 0;
}
