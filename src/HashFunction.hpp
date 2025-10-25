#pragma once
#include <functional>

template<typename T>
class HashFunction {
    protected:
        int m;
        int n;
    public:
        HashFunction(int m, int n) : m(m), n(n) {}
        ~HashFunction() = default;

        int getIndex(T input) const {
            return (std::hash<T>{}(input) + std::hash<std::string>{}(std::to_string(this->n)))% m;
        }

};

