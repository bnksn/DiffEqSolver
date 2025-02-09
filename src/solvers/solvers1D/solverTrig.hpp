#pragma once

#include "../../input/userInputs.hpp"
#include "solver1D.hpp"

class SolverTrig final : public Solver1D {
   private:
    TrigFunc trigFunc;

    [[nodiscard]]
    double evaluateTrig(const double input) const;

   public:
    SolverTrig(const double xFinal, const int xNumSteps, const double yInitial,
               const std::vector<double>& coeffs, const TrigFunc trigFunc) noexcept;

    [[nodiscard]]
    std::vector<double> solve() const final;
};