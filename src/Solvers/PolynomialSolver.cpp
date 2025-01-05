#include "PolynomialSolver.hpp"

PolynomialSolver::PolynomialSolver(const CoeffsFive coeffs, const double dt,
                                   const int numSteps)
    : Solver(dt, numSteps) {
    this->coeffs = coeffs;
}

double PolynomialSolver::rhsFunction(const double t) const {
    return coeffs.A + coeffs.B * t + coeffs.C * t * t + coeffs.D * t * t * t +
           coeffs.E * t * t * t * t;
}