#pragma once

#include "solver2D.hpp"

class SolverHeat final : public Solver2D {
   private:
    double multiplier;

   public:
    SolverHeat(const double xFinal, const int xNumSteps, const double yFinal,
               const int yNumSteps, const std::vector<double>& zInitial,
               const double thermalDiffusivity,
               const BoundaryCondition boundaryCondition) noexcept;

    [[nodiscard]]
    std::vector<double> solve() const final;
};