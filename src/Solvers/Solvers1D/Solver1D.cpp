#include "Solver1D.hpp"

#include <cmath>

Solver1D::Solver1D(const double xFinal, const int xNumSteps,
                   const double yInitial, const std::vector<double>& coeffs)
    : Solver(xFinal, xNumSteps) {
    this->yInitial = yInitial;
    this->coeffs = coeffs;
}