#include <iostream>
#include <cmath>
#include <fstream>
#include "BloomFilter.hpp"

#define N_K_TEST 50

int count_coll(float m, float n, int k = 0, int it = 0);
void test_coll(std::string path); 

int main() {
    test_coll("false_pos.txt");
    return 0;
}

int count_coll(float m, float n, int k, int it) {
    BloomFilter<std::string> *string_bloom;
    if (k == 0) k = std::ceil(m/n*std::log(2));
    if (it == 0) it = 5*n;
    string_bloom = new BloomFilter<std::string>(m, k);
    
    int n_false_pos = 0;

    for (int i = 0; i < n; i++) {
        string_bloom->insert(std::to_string(i));
    }

    for (int i = n; i < it; i++) {
        if (string_bloom->isInserted(std::to_string(i))) {
            n_false_pos++;
        }
    }

    return n_false_pos;
}

void iteration_coll(int m, int n, std::ofstream *output_file) {
    *output_file << "(" << m << ";" << n << ")";
    for (int j = 1; j < N_K_TEST; j++) {
        *output_file << "[" << j << "," << count_coll(m, n, j, 5000) << "]" << ",";
    }
    *output_file << std::endl;
}

void test_coll(std::string path) {
    std::ofstream output_file (path);
    if (output_file.is_open()) {
        iteration_coll(5000, 1000, &output_file);
        iteration_coll(10000, 1000, &output_file);
        iteration_coll(15000, 1000, &output_file);
        iteration_coll(50000, 1000, &output_file);
        iteration_coll(1000, 100, &output_file);
        iteration_coll(1000, 200, &output_file);
        iteration_coll(1000, 500, &output_file);
    } else {
        std::cerr << "Error opening output file";
    }
    output_file.close(); 

}
