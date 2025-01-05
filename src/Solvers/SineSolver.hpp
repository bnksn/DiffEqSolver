#pragma once

#include "Solver.hpp"

class SineSolver : public Solver {
   private:
    CoeffsTwo coeffs;
    double rhsFunction(const double t) const override;

   public:
    SineSolver(const CoeffsTwo coeffs, const double dt, const int numSteps);
};