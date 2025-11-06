#pragma once
#include <memory>
#include "HashFunction.hpp"

class HashFunctionFactory {
    protected:
        size_t it = 0;
    public:
        HashFunctionFactory() = default;
        template<typename T>
        std::unique_ptr<HashFunction<T>> createHashFunction(size_t m) {
            return std::make_unique<HashFunction<T>>(m, this->it++);
        }
};

