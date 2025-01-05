#pragma once

#include "Solver.hpp"

class PolynomialSolver : public Solver {
   private:
    CoeffsFive coeffs;
    double rhsFunction(const double t) const override;

   public:
    PolynomialSolver(const CoeffsFive coeffs, const double dt,
                     const int numSteps);
};