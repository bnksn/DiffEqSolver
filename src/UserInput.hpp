#pragma once

#include "FunctionInputs.hpp"

struct UserInput {
    FunctionInputs rhsFunc;
    double dt;
    unsigned int numSteps;
};