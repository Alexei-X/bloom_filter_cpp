#pragma once
#include <functional>
#include <memory>
#include "ModuloHashFunction.h"

class HashFunctionFactory {
public:
    HashFunctionFactory() = default;
    std::unique_ptr<HashFunction> createHashFunction(int m) const;
};
