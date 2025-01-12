#include "Solver1D.hpp"

#include <cmath>

Solver1D::Solver1D(const double xFinal, const int xNumSteps,
                   const double yInitial,
                   const std::vector<double>& coeffs) noexcept
    : Solver() {
    this->xFinal = xFinal;
    this->xNumSteps = xNumSteps;
    this->dx = xFinal / xNumSteps;
    this->yInitial = yInitial;
    this->coeffs = coeffs;
}