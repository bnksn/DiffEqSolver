#include "CosineSolver.hpp"

CosineSolver::CosineSolver(const Coeffs coeffs, const double dt,
                           const int numSteps)
    : Solver(coeffs, dt, numSteps) {}

double CosineSolver::rhsFunction(const double t) const {
    return coeffs.A * std::cos(coeffs.B * t);
}