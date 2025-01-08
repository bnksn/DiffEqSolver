#include "SineSolver.hpp"

#include <cmath>

SineSolver::SineSolver(const double dt, const int numSteps,
                       const std::vector<int>& coeffs)
    : Solver(dt, numSteps, coeffs) {}

double SineSolver::rhsFunction(const double t) const {
    return coeffs[0] * std::sin(coeffs[1] * t);
}