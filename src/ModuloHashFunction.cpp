#include "ModuloHashFunction.h"

int ModuloHashFunction::getIndex(int input) const {
    return input % m;
}

