#pragma once
#include <functional>

template<typename T>
class HashFunction {
protected:
    int m;
public:
    HashFunction(int m) : m(m) {}
    ~HashFunction() = default;

    int getIndex(T input) const {
        return std::hash<T>{}(input) % m;
    }

};
