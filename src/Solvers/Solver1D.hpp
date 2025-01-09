#pragma once

#include <vector>

#include "Solver.hpp"

class Solver1D : public Solver {
   public:
    Solver1D(const double xFinal, const unsigned int xNumSteps);
    std::vector<double> SineSolve(const double yInitial,
                                  const std::vector<double>& coeffs) const;
    std::vector<double> PolynomialSolve(
        const double yInitial, const std::vector<double>& coeffs) const;
};