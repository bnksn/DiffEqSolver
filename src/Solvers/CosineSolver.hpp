#pragma once

#include "Solver.hpp"

class CosineSolver : public Solver {
   private:
    double rhsFunction(const double t) const override;

   public:
    CosineSolver(const double dt, const int numSteps,
                 const std::vector<int>& coeffs);
};