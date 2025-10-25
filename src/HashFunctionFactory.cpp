#include "HashFunctionFactory.hpp"

template<typename T>
std::unique_ptr<HashFunction<T>> HashFunctionFactory::createHashFunction(int m) const {
    return std::make_unique<HashFunction<T>>(HashFunction<T>(m));
}

template std::unique_ptr<HashFunction<int>> HashFunctionFactory::createHashFunction<int>(int) const;
template std::unique_ptr<HashFunction<std::string>> HashFunctionFactory::createHashFunction<std::string>(int) const;


