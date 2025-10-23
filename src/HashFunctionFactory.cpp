#include "HashFunctionFactory.h"

std::unique_ptr<HashFunction> HashFunctionFactory::createHashFunction(int m) const {
    return std::make_unique<ModuloHashFunction>(m);
}

