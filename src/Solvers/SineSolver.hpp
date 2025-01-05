#pragma once

#include "Solver.hpp"

class SineSolver : public Solver {
   private:
    double rhsFunction(const double t) const override;

   public:
    SineSolver(const Coeffs coeffs, const double dt, const int numSteps);
};