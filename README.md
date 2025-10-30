# bloom_filter_cpp

A lightweight, easy-to-read C++ implementation of a Bloom filter — a space-efficient probabilistic data structure for set membership tests that allows false positives but no false negatives. This repository provides a minimal, practical implementation suitable for learning, embedding, or integrating into larger C++ projects.

## Table of Contents
- [About](#about)
- [Language composition](#language-composition)
- [Requirements](#requirements)
- [Build and install](#build-and-install)
- [Usage examples](#usage-examples)
  - [C++ example](#c-example)
  - [Quick build-and-run example (no CMake)](#quick-build-and-run-example-no-cmake)
- [Parameters & quick theory](#parameters--quick-theory)
- [License](#license)
- [Contact](#contact)

## About
A Bloom filter stores a compact bitset and a small number of hash functions to probabilistically record membership of items. This implementation focuses on clarity, low dependencies (C++ Standard Library only), and reasonable performance for memory-constrained contexts.

## Language composition
- C++: ~68.5%
- Python: ~21.8% (tests/tools)
- Makefile: ~9.7%

## Requirements
- A modern C++ compiler with C++17 support (g++, clang++, MSVC)
- CMake (recommended) or plain compiler toolchain (g++/clang++)
- (Optional) Python 3 if you plan to run Python tests/tools included in the repository

## Build and install

### With CMake (recommended)
```bash
git clone https://github.com/Alexei-X/bloom_filter_cpp.git
cd bloom_filter_cpp
mkdir build && cd build
cmake ..
cmake --build .
# Optionally: cmake --install . --prefix /usr/local
```

### Quick compile without CMake (example)
```bash
g++ -std=c++17 -O3 -Iinclude src/main.cpp -o bloom_example
./bloom_example
```

Adjust paths and filenames according to the repository layout.

## Usage examples

### C++ example
Below is a typical usage pattern. Adapt constructor and method names to the actual API if necessary.

```cpp
#include "bloom_filter.hpp" // adapt the header path as needed
#include <string>

int main() {
    // Create a filter for about 10000 expected items with ~1% false positive rate
    BloomFilter bf(10000 /*expected_items*/, 0.01 /*false_positive_rate*/);

    // Add items
    bf.add("alice@example.com");
    bf.add("bob@example.com");

    // Test membership
    if (bf.contains("alice@example.com")) {
        // probably present
    }

    if (!bf.contains("eve@example.com")) {
        // definitely not present
    }

    // Serialize to file
    bf.save("filter.bin");

    // Load back
    BloomFilter loaded = BloomFilter::load("filter.bin");

    return 0;
}
```

If the repository uses different API names (for example, constructors that take `m` and `k` directly), adapt the example accordingly.

### Quick build-and-run example (no CMake)
```bash
g++ -std=c++17 -O3 examples/example.cpp -Iinclude -o example
./example
```

## Parameters & quick theory
- n = expected number of inserted elements
- p = desired false positive probability
- m = number of bits in the bitset (optimal):
  m = - (n * ln(p)) / (ln 2)^2
- k = number of hash functions (optimal):
  k = (m / n) * ln 2

## License
This project is provided under the MIT License. See the LICENSE file for details.

## Contact
If you have questions, open an issue or contact the repository owner: Alexei-X (https://github.com/Alexei-X)
