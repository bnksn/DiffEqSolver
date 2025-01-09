#pragma once

#include "../../Math/TrigFunc.hpp"
#include "Solver1D.hpp"

class SolverTrig : public Solver1D {
   private:
    TrigFunc trigFunc;
    double evaluateTrig(const int input) const;

   public:
    SolverTrig(const double xFinal, const unsigned int xNumSteps,
               const double yInitial, const std::vector<double>& coeffs,
               const TrigFunc trigFunc);

    std::vector<double> Solve() const override;
};