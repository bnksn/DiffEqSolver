#pragma once

#include <vector>

class Solver1D {
   private:
    double xFinal;
    unsigned int xNumSteps;
    double dx;

   public:
    Solver1D(const double xFinal, const unsigned int xNumSteps);
    std::vector<double> SineSolve(const double yInitial,
                                  const std::vector<double>& coeffs) const;
    std::vector<double> PolynomialSolve(
        const double yInitial, const std::vector<double>& coeffs) const;
};