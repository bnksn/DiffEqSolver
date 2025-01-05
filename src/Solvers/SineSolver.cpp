#include "SineSolver.hpp"

SineSolver::SineSolver(const Coeffs coeffs, const double dt, const int numSteps)
    : Solver(coeffs, dt, numSteps) {}

double SineSolver::rhsFunction(const double t) const {
    return coeffs.A * std::sin(coeffs.B * t);
}