#include "CosineSolver.hpp"

#include <cmath>

CosineSolver::CosineSolver(const double dt, const int numSteps,
                           const std::vector<int>& coeffs)
    : Solver(dt, numSteps, coeffs) {}

double CosineSolver::rhsFunction(const double t) const {
    return coeffs[0] * std::cos(coeffs[1] * t);
}