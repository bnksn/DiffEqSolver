#include "SineSolver.hpp"

SineSolver::SineSolver(const CoeffsTwo coeffs, const double dt,
                       const int numSteps)
    : Solver(dt, numSteps) {
    this->coeffs = coeffs;
}

double SineSolver::rhsFunction(const double t) const {
    return coeffs.A * std::sin(coeffs.B * t);
}