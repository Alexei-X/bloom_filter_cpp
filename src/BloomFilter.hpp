#pragma once
#include "HashFunctionFactory.hpp"
#include <vector>

template<typename T>
class BloomFilter {
    protected:
        size_t m;
        size_t k;
        std::vector<std::unique_ptr<HashFunction<T>>> hash_fcts;
        HashFunctionFactory hash_fcts_fact;
        std::vector<bool> bit_vector;
    public:
        BloomFilter(size_t m, size_t k) : m(m), k(k) {
            this->hash_fcts_fact = HashFunctionFactory();
            for (size_t i = 0; i < k; i++) {
                hash_fcts.push_back(this->hash_fcts_fact.createHashFunction<T>(m));
            }
            for (size_t j = 0; j < m; j++) bit_vector.push_back(false);
        }
        ~BloomFilter() = default;

        bool insert(T element) {
            bool already_ins = isInserted(element);
            for (size_t i = 0; i < this->k; i++) {
                this->bit_vector.at(this->hash_fcts.at(i)->getIndex(element)) = true;
            }
            return !already_ins;
        }
        
        bool isInserted(T element) {
            for (size_t i = 0; i < this->k; i++) {
                if (!this->bit_vector.at(this->hash_fcts.at(i)->getIndex(element))) return false;
            }
            return true;
        }
};

