#pragma once
#include "HashFunctionFactory.hpp"
#include <vector>

template<typename T>
class BloomFilter {
    protected:
        int m;
        int k;
        std::vector<HashFunction<T>&> hash_fcts;
        HashFunctionFactory hash_fcts_fact;
    public:
        BloomFilter(int m, int k) : m(m), k(k) {
            this->hash_fcts_fact = HashFunctionFactory();
            for (int i = 0; i < k; i++) {
                hash_fcts.push_back(this->hash_fcts_fact.createHashFunction<T>(m));
            }
        }
        ~BloomFilter() = default;
        bool insert(T element);
        bool isInserted(T element);
};

