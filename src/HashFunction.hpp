#pragma once
#include <functional>
#include <string>

template<typename T>
class HashFunction {
    protected:
        size_t m;
        int d;
    public:
        HashFunction(size_t m, int d) : m(m), d(d) {}
        ~HashFunction() = default;

        int getIndex(T input) const {
            return (std::hash<T>{}(input) + std::hash<std::string>{}(std::to_string(this->d)))% m;
        }

};

