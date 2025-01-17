#include "solver1D.hpp"

#include <cmath>

Solver1D::Solver1D(const double xFinal, const int xNumSteps,
                   const double yInitial,
                   const std::vector<double>& coeffs) noexcept
    : Solver(),
      xFinal(xFinal),
      xNumSteps(xNumSteps),
      dx(xFinal / xNumSteps),
      yInitial(yInitial),
      coeffs(coeffs) {}