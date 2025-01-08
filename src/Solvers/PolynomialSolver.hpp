#pragma once

#include "Solver.hpp"

class PolynomialSolver : public Solver {
   private:
    double rhsFunction(const double t) const override;

   public:
    PolynomialSolver(const double dt, const int numSteps,
                     const std::vector<int>& coeffs);
};