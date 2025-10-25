#include <iostream>
#include "BloomFilter.hpp"

int main() {

    BloomFilter<std::string> string_bloom = BloomFilter<std::string>(500, 10);
    string_bloom.insert("Alex");
    if (string_bloom.isInserted("Alex")) {
        std::cout << "Alex Inserted" << std::endl;
    }
    if (string_bloom.isInserted("Bob")) {
        std::cout << "Bob Inserted" << std::endl;
    }
    string_bloom.insert("Alexi");
    if (string_bloom.isInserted("Alexi")) {
        std::cout << "Alexi Inserted" << std::endl;
    }

    return 0;
}
