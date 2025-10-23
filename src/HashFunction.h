#pragma once
#include <functional>

class HashFunction {
protected:
    int m;
public:
    explicit HashFunction(int m) : m(m) {}
    virtual ~HashFunction() = default;

    virtual int getIndex(int input) const = 0;
};
