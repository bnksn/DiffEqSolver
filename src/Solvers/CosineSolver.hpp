#pragma once

#include "Solver.hpp"

class CosineSolver : public Solver {
   private:
    CoeffsTwo coeffs;
    double rhsFunction(const double t) const override;

   public:
    CosineSolver(const CoeffsTwo coeffs, const double dt, const int numSteps);
};