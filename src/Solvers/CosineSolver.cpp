#include "CosineSolver.hpp"

CosineSolver::CosineSolver(const CoeffsTwo coeffs, const double dt,
                           const int numSteps)
    : Solver(dt, numSteps) {
    this->coeffs = coeffs;
}

double CosineSolver::rhsFunction(const double t) const {
    return coeffs.A * std::cos(coeffs.B * t);
}