#include "Solver.hpp"

Solver::Solver(const Coeffs coeffs, const double dt, const int numSteps) {
    this->coeffs = coeffs;
    this->dt = dt;
    this->numSteps = numSteps;
}