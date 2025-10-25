#include <iostream>
#include "HashFunctionFactory.hpp"

int main() {

    std::cout << "Hello world !" << std::endl;
    HashFunctionFactory factory = HashFunctionFactory();
    std::unique_ptr<HashFunction<std::string>> fct1 = factory.createHashFunction<std::string>(500);
    std::unique_ptr<HashFunction<std::string>> fct2 = factory.createHashFunction<std::string>(500);
    std::unique_ptr<HashFunction<std::string>> fct3 = factory.createHashFunction<std::string>(500);
    std::cout << fct1->getIndex("Bonjour") << std::endl;
    std::cout << fct2->getIndex("Bonjour") << std::endl;
    std::cout << fct3->getIndex("Bonjour") << std::endl;

    std::vector<bool> vec = {true, false, false};
    std::unique_ptr<HashFunction<std::vector<bool>>> fct_vec = factory.createHashFunction<std::vector<bool>>(100);
    std::unique_ptr<HashFunction<std::vector<bool>>> fct_vec2 = factory.createHashFunction<std::vector<bool>>(100);
    std::cout << fct_vec->getIndex(vec) << std::endl;
    std::cout << fct_vec2->getIndex(vec) << std::endl;

    return 0;
}
