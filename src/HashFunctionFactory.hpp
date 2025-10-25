#pragma once
#include <memory>
#include "HashFunction.hpp"

class HashFunctionFactory {
public:
    HashFunctionFactory() = default;
    template<typename T>
    std::unique_ptr<HashFunction<T>> createHashFunction(int m) const;
};
