#pragma once
#include <functional>
#include <string>

template<typename T>
class HashFunction {
    protected:
        size_t m;
        size_t d;
    public:
        HashFunction(size_t m, int d) : m(m), d(d) {}
        ~HashFunction() = default;

        int getIndex(T input) const {
             size_t h1 = std::hash<T>{}(input);
             size_t h2 = std::hash<std::string>{}(std::to_string(this->d));
             return (h1 + d * h2 + d*d) % m;
        }
};

