#pragma once
#include <memory>
#include "HashFunction.hpp"

class HashFunctionFactory {
    protected:
        int it = 0;
    public:
        HashFunctionFactory() = default;
        template<typename T>
        std::unique_ptr<HashFunction<T>> createHashFunction(int m);
};

