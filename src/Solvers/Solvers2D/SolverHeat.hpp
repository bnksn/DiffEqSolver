#pragma once

#include "../../Math/BoundaryCondition.hpp"
#include "Solver2D.hpp"

class SolverHeat : public Solver2D {
   private:
    double multiplier;

   public:
    SolverHeat(const double xFinal, const int xNumSteps, const double yFinal,
               const int yNumSteps, const std::vector<double>& zInitial,
               const double thermalDiffusivity,
               const BoundaryCondition boundaryCondition);

    [[nodiscard]]
    std::vector<double> Solve() const override;
};