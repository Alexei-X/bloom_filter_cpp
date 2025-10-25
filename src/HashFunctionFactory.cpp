#include "HashFunctionFactory.hpp"

template<typename T>
std::unique_ptr<HashFunction<T>> HashFunctionFactory::createHashFunction(int m) {
    this->it++;
    return std::make_unique<HashFunction<T>>(HashFunction<T>(m, this->it));
}

template std::unique_ptr<HashFunction<int>> HashFunctionFactory::createHashFunction<int>(int);
template std::unique_ptr<HashFunction<std::string>> HashFunctionFactory::createHashFunction<std::string>(int);

