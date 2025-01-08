#include "PolynomialSolver.hpp"

PolynomialSolver::PolynomialSolver(const double dt, const int numSteps,
                                   const std::vector<int>& coeffs)
    : Solver(dt, numSteps, coeffs) {}

double PolynomialSolver::rhsFunction(const double t) const {
    return coeffs[0] + coeffs[1] * t + coeffs[2] * t * t +
           coeffs[3] * t * t * t + coeffs[4] * t * t * t * t;
}