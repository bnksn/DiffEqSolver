#pragma once

#include <vector>

#include "../Math/Point.hpp"
#include "FunctionInputs.hpp"

struct UserInput {
    FunctionInputs rhsFunc;
    std::vector<int> coeffs;
    double dt;
    unsigned int numSteps;
    Point initialValue;
};