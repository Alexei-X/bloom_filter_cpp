#include "HashFunction.h"

class ModuloHashFunction : public HashFunction {
public:
    using HashFunction::HashFunction;

    int getIndex(int input) const;
};

